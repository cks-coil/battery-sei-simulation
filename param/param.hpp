/*
  \file    param.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/ 

#ifndef __INCLUDED_PARAM_HPP__
#define __INCLUDED_PARAM_HPP__

#include <ostream>

class Param{
public:
    Param(void);
    void output(std::ostream &out);
    void setAnodeSurfaceArea(double anodeSurfaceArea);
    void setAnodeReactionRateConstant(double anodeReactionRateConstant);
    void setAnodeMaxLithiumConcentration(double anodeMaxLithiumConcentration);
    void setAnodeInitialLithiumConcentration(double anodeInitialLithiumConcentration);
    void setAnodeParticleRadius(double anodeParticleRadius);
    void setAnodeDiffusionCoefficient(double anodeDiffusionCoefficient);
    void setAnodeSideReactionExchangeCurrentDensity(double anodeSideReactionExchangeCurrentDensity);
    void setCathodeSurfaceArea(double cathodeSurfaceArea);
    void setCathodeReactionRateConstant(double cathodeReactionRateConstant);
    void setCathodeMaxLithiumConcentration(double cathodeMaxLithiumConcentration);
    void setCathodeInitialLithiumConcentration(double cathodeInitialLithiumConcentration);
    void setCathodeParticleRadius(double cathodeParticleRadius);
    void setCathodeDiffusionCoefficient(double cathodeDiffusionCoefficient);
    void setLiquidPhaseLithiumConcentration(double liquidPhaseLithiumConcentration);
    void setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential);
    void setTransferCoefficients(double transferCoefficients);
    void setTemperature(double temperature);
    void setAppliedCurrent(double appliedCurrent);
    void setSEILocalEquilibriumPotential(double SEILocalEquilibriumPotential);
    void setSEIElectronicConductivity(double SEIElectronicConductivity);
    void setSEIUnitArea(double SEIUnitArea);
    void setSEIUnitThickness(double SEIUnitThickness);
    void setUpperCutoffVoltage(double upperCutoffVoltage);
    void setLowerCutoffVoltage(double lowerCutoffVoltage);
    double getAnodeSurfaceArea(void);
    double getAnodeReactionRateConstant(void);
    double getAnodeMaxLithiumConcentration(void);
    double getAnodeInitialLithiumConcentration(void);
    double getAnodeParticleRadius(void);
    double getAnodeDiffusionCoefficient(void);
    double getAnodeSideReactionExchangeCurrentDensity(void);
    double getCathodeSurfaceArea(void);
    double getCathodeReactionRateConstant(void);
    double getCathodeMaxLithiumConcentration(void);
    double getCathodeInitialLithiumConcentration(void);
    double getCathodeParticleRadius(void);
    double getCathodeDiffusionCoefficient(void);
    double getLiquidPhaseLithiumConcentration(void);
    double getLiquidPhaseLocalPotential(void);
    double getTransferCoefficients(void);
    double getTemperature(void);
    double getAppliedCurrent(void);
    double getSEILocalEquilibriumPotential(void);
    double getSEIElectronicConductivity(void);
    double getSEIUnitArea(void);
    double getSEIUnitThickness(void);
    double getUpperCutoffVoltage(void);
    double getLowerCutoffVoltage(void);
private:
    double anodeSurfaceArea;
    double anodeReactionRateConstant;
    double anodeMaxLithiumConcentration;
    double anodeInitialLithiumConcentration;
    double anodeParticleRadius;
    double anodeDiffusionCoefficient;
    double anodeSideReactionExchangeCurrentDensity;
    double cathodeSurfaceArea;
    double cathodeReactionRateConstant;
    double cathodeMaxLithiumConcentration;
    double cathodeInitialLithiumConcentration;
    double cathodeParticleRadius;
    double cathodeDiffusionCoefficient;
    double liquidPhaseLithiumConcentration;
    double liquidPhaseLocalPotential;
    double transferCoefficients;
    double temperature;
    double appliedCurrent;
    double SEILocalEquilibriumPotential;
    double SEIElectronicConductivity;
    double SEIUnitArea;
    double SEIUnitThickness;
    double upperCutoffVoltage;
    double lowerCutoffVoltage;
};

std::ostream &operator<<(std::ostream &out, Param &tgt);

#endif



