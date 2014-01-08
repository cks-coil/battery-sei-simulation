/*
  \file    state.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_STATE_HPP__
#define __INCLUDED_STATE_HPP__

#include "param.hpp"

class State{
public:
    State(void);
    void setParam(Param *p);
    void setSolidPhaseLocalPotential(double solidPhaseLocalPotential);
    void setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential);
    void setAnodeIntercalationCurrentDensity(double anodeIntercalationCurrentDensity);
    void setAnodeSideReactionCurrentDensity(double anodeSideReactionCurrentDensity);
    void setAnodeLocalEquilibriumPotential(double anodeLocalEquilibriumPotential);
    void setSEIThickness(double SEIThickness);
    double getSolidPhaseLocalPotential(void);
    double getLiquidPhaseLocalPotential(void);
    double getAnodeIntercalationCurrentDensity(void);
    double getAnodeSideReactionCurrentDensity(void);
    double getAnodeLocalEquilibriumPotential(void);
private:
    Param *p;
    double solidPhaseLocalPotential;
    double liquidPhaseLocalPotential;
    double anodeIntercalationCurrentDensity;
    double anodeSideReactionCurrentDensity;
    double anodeLocalEquilibriumPotential;
};

#endif
  
