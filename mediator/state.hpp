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
    void outputMultiLine(std::ostream &out);
    void outputSingleLine(std::ostream &out);
    void setAppliedCurrent(double appliedCurrent);
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
    void setCellVoltage(double cellVoltage);
    void setCapacity(double capacity);
    void setSEIThickness(double SEIThickness);
    void setLithiumLoss(double lithiumLoss);
    void setDimensionlessLithiumLoss(double dimensionlessLithiumLoss);
    double getAppliedCurrent(void);
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
    double getCellVoltage(void);
    double getCapacity(void);
    double getSEIThickness(void);
    double getLithiumLoss(void);
    double getDimensionlessLithiumLoss(void);
private:
    double appliedCurrent;
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
    double cellVoltage;
    double capacity;
    double SEIThickness;
    double lithiumLoss;
    double dimensionlessLithiumLoss;
};

std::ostream &operator<<(std::ostream &out, State &tgt);

#endif

