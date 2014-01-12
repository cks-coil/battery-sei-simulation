/*
  \file    state.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_STATE_HPP__
#define __INCLUDED_STATE_HPP__

#include <ostream>
#include "param.hpp"

class State{
public:
    State(void);
    void operator=(State &source);
    void output(std::ostream &out);
    void setAnodeSideReactionCurrent(double anodeSideReactionCurrent);
    void setAnodeLocalPotential(double anodeLocalPotential);
    void setAnodeLocalEquilibriumPotential(double anodeLocalEquilibriumPotential);
    void setAnodeOverPotential(double anodeOverPotential);
    void setAnodeAverageLithiumConcentration(double anodeAverageLithiumConcentration);
    void setAnodeSurfaceLithiumConcentration(double anodeSurfaceLithiumConcentration);
    void setAnodeDimensionlessLithiumConcentration(double anodeDimensionlessLithiumConcentration);
    void setCathodeLocalPotential(double cathodeLocalPotential);
    void setCathodeLocalEquilibriumPotential(double cathodeLocalEquilibriumPotential);
    void setCathodeOverPotential(double cathodeOverPotential);
    void setCathodeAverageLithiumConcentration(double cathodeAverageLithiumConcentration);
    void setCathodeSurfaceLithiumConcentration(double cathodeSurfaceLithiumConcentration);
    void setCathodeDimensionlessLithiumConcentration(double cathodeDimensionlessLithiumConcentration);
    void setSEIThickness(double SEIThickness);
    double getAnodeSideReactionCurrent(void);
    double getAnodeLocalPotential(void);
    double getAnodeLocalEquilibriumPotential(void);
    double getAnodeOverPotential(void);
    double getAnodeAverageLithiumConcentration(void);
    double getAnodeSurfaceLithiumConcentration(void);
    double getAnodeDimensionlessLithiumConcentration(void);
    double getCathodeLocalPotential(void);
    double getCathodeLocalEquilibriumPotential(void);
    double getCathodeOverPotential(void);
    double getCathodeAverageLithiumConcentration(void);
    double getCathodeSurfaceLithiumConcentration(void);
    double getCathodeDimensionlessLithiumConcentration(void);
    double getSEIThickness(void);
private:
    double anodeSideReactionCurrent;
    double anodeLocalPotential;
    double anodeLocalEquilibriumPotential;
    double anodeOverPotential;
    double anodeAverageLithiumConcentration;
    double anodeSurfaceLithiumConcentration;
    double anodeDimensionlessLithiumConcentration;
    double cathodeLocalPotential;
    double cathodeLocalEquilibriumPotential;
    double cathodeOverPotential;
    double cathodeAverageLithiumConcentration;
    double cathodeSurfaceLithiumConcentration;
    double cathodeDimensionlessLithiumConcentration;
    double SEIThickness;
};

#endif
  
