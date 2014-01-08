/*
  \file    param.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/ 

#ifndef __INCLUDED_PARAM_HPP__
#define __INCLUDED_PARAM_HPP__


class Param{
public:
    Param(void);
    void setAnodeSurfaceArea(double anodeSurfaceArea);
    void setAnodeReactionRateConstant(double anodeReactionRateConstant);
    void setAnodeMaxLithiumConcentration(double anodeMaxLithiumConcentration);
    void setAnodeParticleRadius(double anodeParticleRadius);
    void setAnodeDiffusionCoefficient(double anodeDiffusionCoefficient);
    void setAnodeSideReactionExchangeCurrentDensity(double anodeSideReactionExchangeCurrentDensity);
    void setCathodeSurfaceArea(double cathodeSurfaceArea);
    void setCathodeReactionRateConstant(double cathodeReactionRateConstant);
    void setCathodeMaxLithiumConcentration(double cathodeMaxLithiumConcentration);
    void setCathodeParticleRadius(double cathodeParticleRadius);
    void setCathodeDiffusionCoefficient(double cathodeDiffusionCoefficient);
    void setLiquidPhaseLocalConcentration(double liquidPhaseLocalConcentration);
    void setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential);
    void setTransferCoefficients(double transferCoefficients);
    void setTemperature(double temperature);
    void setAppliedCurrent(double appliedCurrent);
    void setUnitSEIArea(double unitSEIArea);
    void setUnitSEIThickness(double unitSEIThickness);
    double getAnodeSurfaceArea(void);
    double getAnodeReactionRateConstant(void);
    double getAnodeMaxLithiumConcentration(void);
    double getAnodeParticleRadius(void);
    double getAnodeDiffusionCoefficient(void);
    double getAnodeSideReactionExchangeCurrentDensity(void);
    double getCathodeSurfaceArea(void);
    double getCathodeReactionRateConstant(void);
    double getCathodeMaxLithiumConcentration(void);
    double getCathodeParticleRadius(void);
    double getCathodeDiffusionCoefficient(void);
    double getLiquidPhaseLocalConcentration(void);
    double getLiquidPhaseLocalPotential(void);
    double getTransferCoefficients(void);
    double getTemperature(void);
    double getAppliedCurrent(void);
    double getUnitSEIArea(void);
    double getUnitSEIThickness(void);
private:
    double anodeSurfaceArea;
    double anodeReactionRateConstant;
    double anodeMaxLithiumConcentration;
    double anodeParticleRadius;
    double anodeDiffusionCoefficient;
    double anodeSideReactionExchangeCurrentDensity;
    double cathodeSurfaceArea;
    double cathodeReactionRateConstant;
    double cathodeMaxLithiumConcentration;
    double cathodeParticleRadius;
    double cathodeDiffusionCoefficient;
    double liquidPhaseLocalConcentration;
    double liquidPhaseLocalPotential;
    double transferCoefficients;
    double temperature;
    double appliedCurrent;
    double unitSEIArea;
    double unitSEIThickness;
};

#endif



