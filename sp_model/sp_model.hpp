/*
  \file    sp_model.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_SP_MODEL__
#define __INCLUDED_SP_MODEL__

#include "param.hpp"
#include "state.hpp"

class SPModel{
public:
    SPModel(double dt);
    void setState(State *s);
    void setParam(Param *p);
    void step(void);
    int getStepNum(void);
    double getTime(void);
private:
    double dt;
    double time;
    int stepNum;
    State *s;
    Param *p;
    void init(void);
    void calcAnodeAverageLithiumConcentration(void);
    void calcCathodeAverageLithiumConcentration(void);
    void calcAnodeSurfaceLithiumConcentration(void);
    void calcCathodeSurfaceLithiumConcentration(void);
    void calcAnodeDimensionlessLithiumConcentration(void);
    void calcCathodeDimensionlessLithiumConcentration(void);
    void calcCathodeLocalEquilibriumPotential(void);
    void calcAnodeLocalEquilibriumPotential(void);
    void calcAnodeOverPotential(void);
    void calcCathodeOverPotential(void);
    void calcAnodeLocalPotential(void);
    void calcCathodeLocalPotential(void);
    void calcCellVoltage(void);
    void calcAnodeSideReactionCurrent(void);
    void calcSEIThickness(void);
    void updateTime(void);
};

#endif
