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
    void setAdsorptionOneSideCoeff(double adsorptionOneSideCoeff);
    void setAdsorptionTwoSideCoeff(double adsorptionTwoSideCoeff);
    void setAdsorptionThreeSideCoeff(double adsorptionThreeSideCoeff);
    void setAdsorptionFourSideCoeff(double adsorptionFourSideCoeff);
    void setSPModelDeltaTime(double SPModelDeltaTime);
    void setKMCNullTransitionRate(double KMCNullTransitionRate);
    void setKMCSurfaceSizeX(int KMCSurfaceSizeX);
    void setKMCSurfaceSizeY(int KMCSurfaceSizeY);
    void setMediatorEndCycles(int MediatorEndCycles);
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
    double getAdsorptionOneSideCoeff(void);
    double getAdsorptionTwoSideCoeff(void);
    double getAdsorptionThreeSideCoeff(void);
    double getAdsorptionFourSideCoeff(void);
    double getUpperCutoffVoltage(void);
    double getLowerCutoffVoltage(void);
    double getSPModelDeltaTime(void);
    double getKMCNullTransitionRate(void);
    int getKMCSurfaceSizeX(void);
    int getKMCSurfaceSizeY(void);
    int getMediatorEndCycles(void);
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
    double adsorptionOneSideCoeff;
    double adsorptionTwoSideCoeff;
    double adsorptionThreeSideCoeff;
    double adsorptionFourSideCoeff;
    double SPModelDeltaTime;
    double KMCNullTransitionRate;
    int KMCSurfaceSizeX;
    int KMCSurfaceSizeY;
    int MediatorEndCycles;
};

std::ostream &operator<<(std::ostream &out, Param &tgt);

#endif
