/*
  \file    kmc_surface.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>

  面心立方格子を表面に成長させる

  横から見たイメージとしては下のような感じになる(数字がsite:nに対応する,実際には周期境界あり)
  1_2_3_4_5_..._N
  _1_2_3_4_5_..._N
  1_2_3_4_5_..._N
  上のようになっている場合、site:1~Nは全て、三層になっていると言える
  例えば二層目の"2"の下には一層目の"2"と"3"が、上には三層目の"2"と"3"が存在している

  プログラム内では、n*mの配列を持ち、そこに高さ(何層目まで粒子があるか)を持っている
*/

#ifndef __INCLUDED_KMC_SURFACE_HPP__
#define __INCLUDED_KMC_SURFACE_HPP__

#include <vector>
#include <iostream>
#include "param.hpp"
#include "state.hpp"

typedef enum{
    RIGHT,
    LEFT,
    FRONT,
    BACK
} orthDir; //orthogonal direction

typedef enum{
    RIGHT_FRONT,
    RIGHT_BACK,
    LEFT_FRONT,
    LEFT_BACK
} diaDir; //diaglonal direction

class KMCSurface{
public:
    KMCSurface(void);
    void setParam(Param *param);
    void setState(State *state);
    void updateState(void);
    bool isValid(int n); // nに対応するsiteは存在するか?(0 <= n < x*y)
    bool isTop(int n);  // nに対応するsiteの上に何も乘っていないか?(desorptionできるか?)
    bool isFlat(int n); // nに対応するsiteの下にに位置する4つが全て専有されているか?(adsorptionできるか?)
    int getNumSite(void);
    int getNumSide(int n);
    int getNumSideUp(int n);
    double getSurfaceArea(void);
    double getSEIThicknessPoint(int n);
    double getSEIThicknessAve(void);
    void adsorb(int n);
    void desorb(int n);
    void output(std::ostream &out);
    void analyze(std::ostream &out);
private:
    double SEIThicknessAve;
    Param *p;
    State *s;
    std::vector<int> surface;
    std::vector<bool> isFlatTable;
    std::vector<int> numSideUpTable;
    void calcSEIThicknessAve(void);
    void changeXYtoN(int x, int y, int *n);
    void changeNtoXY(int n, int *x, int *y);
    void boundaryXY(int *x, int *y);
    int getSideN(int n, orthDir dir);
    int getUpDownSideN(int n, int z, diaDir dir);
    void updateIsFlatTable(int n);
    bool judgeIsFlat(int n);
    void updateNumSideUpTable(int n);
    int calcNumSideUp(int n);
};

std::ostream &operator<<(std::ostream &out, KMCSurface &tgt);

#endif
