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
    void setECReductionPreFactorNoSide(double ECReductionPotential);
    void setECReductionPreFactorOneSide(double ECReductionPotential);
    void setECReductionPreFactorTwoSide(double ECReductionPotential);
    void setECReductionPreFactorThreeSide(double ECReductionPotential);
    void setECReductionPreFactorFourSide(double ECReductionPotential);
    void setECReorganizationEnergyNoSide(double ECReorganizationEnergyNoSide);
    void setECReorganizationEnergyOneSide(double ECReorganizationEnergyOneSide);
    void setECReorganizationEnergyTwoSide(double ECReorganizationEnergyTwoSide);
    void setECReorganizationEnergyThreeSide(double ECReorganizationEnergyThreeSide);
    void setECReorganizationEnergyFourSide(double ECReorganizationEnergyFourSide);
    void setECReductionPotentialNoSide(double ECReductionPotentialNoSide);
    void setECReductionPotentialOneSide(double ECReductionPotentialOneSide);
    void setECReductionPotentialTwoSide(double ECReductionPotentialTwoSide);
    void setECReductionPotentialThreeSide(double ECReductionPotentialThreeSide);
    void setECReductionPotentialFourSide(double ECReductionPotentialFourSide);
    void setSEIElectronicConductivity(double SEIElectronicConductivity);
    void setSEIIonicConductivity(double SEIIonicConductivity);
    void setSEIUnitArea(double SEIUnitArea);
    void setSEIUnitThickness(double SEIUnitThickness);
    void setUpperCutoffVoltage(double upperCutoffVoltage);
    void setLowerCutoffVoltage(double lowerCutoffVoltage);
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
    double getECReductionPreFactorNoSide(void);
    double getECReductionPreFactorOneSide(void);
    double getECReductionPreFactorTwoSide(void);
    double getECReductionPreFactorThreeSide(void);
    double getECReductionPreFactorFourSide(void);
    double getECReorganizationEnergyNoSide(void);
    double getECReorganizationEnergyOneSide(void);
    double getECReorganizationEnergyTwoSide(void);
    double getECReorganizationEnergyThreeSide(void);
    double getECReorganizationEnergyFourSide(void);
    double getECReductionPotentialNoSide(void);
    double getECReductionPotentialOneSide(void);
    double getECReductionPotentialTwoSide(void);
    double getECReductionPotentialThreeSide(void);
    double getECReductionPotentialFourSide(void);
    double getSEIElectronicConductivity(void);
    double getSEIIonicConductivity(void);
    double getSEIUnitArea(void);
    double getSEIUnitThickness(void);
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
    double ECReductionPreFactorNoSide;
    double ECReductionPreFactorOneSide;
    double ECReductionPreFactorTwoSide;
    double ECReductionPreFactorThreeSide;
    double ECReductionPreFactorFourSide;
    double ECReorganizationEnergyNoSide;
    double ECReorganizationEnergyOneSide;
    double ECReorganizationEnergyTwoSide;
    double ECReorganizationEnergyThreeSide;
    double ECReorganizationEnergyFourSide;
    double ECReductionPotentialNoSide;
    double ECReductionPotentialOneSide;
    double ECReductionPotentialTwoSide;
    double ECReductionPotentialThreeSide;
    double ECReductionPotentialFourSide;
    double SEIElectronicConductivity;
    double SEIIonicConductivity;
    double SEIUnitArea;
    double SEIUnitThickness;
    double upperCutoffVoltage;
    double lowerCutoffVoltage;
    double SPModelDeltaTime;
    double KMCNullTransitionRate;
    int KMCSurfaceSizeX;
    int KMCSurfaceSizeY;
    int MediatorEndCycles;
};

std::ostream &operator<<(std::ostream &out, Param &tgt);

#endif
