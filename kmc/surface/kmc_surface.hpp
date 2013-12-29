/*
  \file    kmc_surface.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>

  面心立方格子を表面に成長させる

  横から見たイメージとしては下のような感じになる(数字がsite:nに対応する,実際には周期境界あり)
  1 2 3 4 5 ... N
   1 2 3 4 5 ... N
  1 2 3 4 5 ... N
  上のようになっている場合、site:1~Nは全て、三層になっていると言える
  例えば二層目の"2"の下には一層目の"2"と"3"が、上には三層目の"2"と"3"が存在している

  プログラム内では、n*mの配列を持ち、そこに高さ(何層目まで粒子があるか)を持っている
*/

#ifndef __INCLUDED_KMC_SURFACE_HPP__
#define __INCLUDED_KMC_SURFACE_HPP__

#include <vector>
#include <iostream>
#include "kmc_param.h"

class KMCSurface{
public:
    KMCSurface(int x, int y);
    void setParam(KMCParam *param);
    void update(void);
    bool isValid(int n); // nに対応するsiteは存在するか?(0 <= n < x*y)
    bool isTop(int n);  // nに対応するsiteの上に何も乘っていないか?(desorptionできるか?)
    bool isFlat(int n); // nに対応するsiteの下にに位置する4つが全て専有されているか?(adsorptionできるか?)
    int getNumSite(void);
    int getNumSide(int n);
    double getDeltaPoint(int n);
    double getDeltaAve(void);
    void adsorb(int n);
    void desorb(int n);
    void output(std::ostream &out);
private:
    int xNum, yNum;
    double deltaAve;
    KMCParam *p;
    std::vector<int> surface;
    double calcDeltaAve(void);
    void XYtoN(int x, int y, int *n);
    void NtoXY(int n, int *x, int *y);
    void boundaryXY(int *x, int *y);
};

std::ostream &operator<<(std::ostream &out, State &tgt);

#endif
