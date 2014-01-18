/*
  \file    param.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/ 
#include <math.h>
#include "constant.hpp"
#include "param.hpp"

Param::Param(void){
    anodeSurfaceArea = 0;
    anodeReactionRateConstant = 0;
    anodeMaxLithiumConcentration = 0;
    anodeInitialLithiumConcentration = 0;
    anodeParticleRadius = 0;
    anodeDiffusionCoefficient = 0;
    anodeSideReactionExchangeCurrentDensity = 0;
    cathodeSurfaceArea = 0;
    cathodeReactionRateConstant = 0;
    cathodeMaxLithiumConcentration = 0;
    cathodeInitialLithiumConcentration = 0;
    cathodeParticleRadius = 0;
    cathodeDiffusionCoefficient = 0;
    liquidPhaseLithiumConcentration = 0;
    liquidPhaseLocalPotential = 0;
    transferCoefficients = 0;
    temperature = 0;
    appliedCurrent = 0;
    SEILocalEquilibriumPotential = 0;
    SEIElectronicConductivity = 0;
    SEIUnitArea = 0;
    SEIUnitThickness = 0;
    upperCutoffVoltage = 0;
    lowerCutoffVoltage = 0;
    adsorptionOneSideCoeff = 0;
    adsorptionTwoSideCoeff = 0;
    adsorptionThreeSideCoeff = 0;
    adsorptionFourSideCoeff = 0;
    SPModelDeltaTime = 0;
    KMCSurfaceSizeX = 0;
    KMCSurfaceSizeY = 0;
    MediatorEndCycles = 0;
}

void Param::output(std::ostream &out){
    out << "# anodeSurfaceArea: " << anodeSurfaceArea << std::endl
        << "# anodeReactionRateConstant: " << anodeReactionRateConstant << std::endl
        << "# anodeMaxLithiumConcentration: " << anodeMaxLithiumConcentration << std::endl
        << "# anodeInitialLithiumConcentration: " << anodeInitialLithiumConcentration << std::endl
        << "# anodeParticleRadius: " << anodeParticleRadius << std::endl
        << "# anodeDiffusionCoefficient: " << anodeDiffusionCoefficient << std::endl
        << "# anodeSideReactionExchangeCurrentDensity: " << anodeSideReactionExchangeCurrentDensity << std::endl
        << "# cathodeSurfaceArea: " << cathodeSurfaceArea << std::endl
        << "# cathodeReactionRateConstant: " << cathodeReactionRateConstant << std::endl
        << "# cathodeMaxLithiumConcentration: " << cathodeMaxLithiumConcentration << std::endl
        << "# cathodeInitialLithiumConcentration: " << cathodeInitialLithiumConcentration << std::endl
        << "# cathodeParticleRadius: " << cathodeParticleRadius << std::endl
        << "# cathodeDiffusionCoefficient: " << cathodeDiffusionCoefficient << std::endl
        << "# liquidPhaseLithiumConcentration: " << liquidPhaseLithiumConcentration << std::endl
        << "# liquidPhaseLocalPotential: " << liquidPhaseLocalPotential << std::endl
        << "# transferCoefficients: " << transferCoefficients << std::endl
        << "# temperature: " << temperature << std::endl
        << "# appliedCurrent: " << appliedCurrent << std::endl
        << "# SEILocalEquilibriumPotential: " << SEILocalEquilibriumPotential << std::endl
        << "# SEIElectronicConductivity: " << SEIElectronicConductivity << std::endl
        << "# SEIUnitArea: " << SEIUnitArea << std::endl
        << "# SEIUnitThickness: " << SEIUnitThickness << std::endl
        << "# upperCutoffVoltage: " << upperCutoffVoltage << std::endl
        << "# lowerCutoffVoltage: " << lowerCutoffVoltage << std::endl
        << "# adsorptionOneSideCoeff" << adsorptionOneSideCoeff << std::endl
        << "# adsorptionTwoSideCoeff" << adsorptionTwoSideCoeff << std::endl
        << "# adsorptionThreeSideCoeff" << adsorptionThreeSideCoeff << std::endl
        << "# adsorptionFourSideCoeff" << adsorptionFourSideCoeff << std::endl
        << "# SPModelDeltaTime: " << SPModelDeltaTime << std::endl
        << "# KMCSurfaceSizeX: " << KMCSurfaceSizeX << std::endl
        << "# KMCSurfaceSizeY: " << KMCSurfaceSizeY << std::endl
        << "# MediatorEndCycles: " << MediatorEndCycles << std::endl;
}

void Param::setAnodeSurfaceArea(double anodeSurfaceArea){ this->anodeSurfaceArea = anodeSurfaceArea; }
void Param::setAnodeReactionRateConstant(double anodeReactionRateConstant){ this->anodeReactionRateConstant = anodeReactionRateConstant; }
void Param::setAnodeMaxLithiumConcentration(double anodeMaxLithiumConcentration){ this->anodeMaxLithiumConcentration = anodeMaxLithiumConcentration; }
void Param::setAnodeInitialLithiumConcentration(double anodeInitialLithiumConcentration){ this->anodeInitialLithiumConcentration = anodeInitialLithiumConcentration; }
void Param::setAnodeParticleRadius(double anodeParticleRadius){ this->anodeParticleRadius = anodeParticleRadius; }
void Param::setAnodeDiffusionCoefficient(double anodeDiffusionCoefficient){ this->anodeDiffusionCoefficient = anodeDiffusionCoefficient; }
void Param::setAnodeSideReactionExchangeCurrentDensity(double anodeSideReactionExchangeCurrentDensity){ this->anodeSideReactionExchangeCurrentDensity = anodeSideReactionExchangeCurrentDensity; }
void Param::setCathodeSurfaceArea(double cathodeSurfaceArea){ this->cathodeSurfaceArea = cathodeSurfaceArea; }
void Param::setCathodeReactionRateConstant(double cathodeReactionRateConstant){ this->cathodeReactionRateConstant = cathodeReactionRateConstant; }
void Param::setCathodeMaxLithiumConcentration(double cathodeMaxLithiumConcentration){ this->cathodeMaxLithiumConcentration = cathodeMaxLithiumConcentration; }
void Param::setCathodeInitialLithiumConcentration(double cathodeInitialLithiumConcentration){ this->cathodeInitialLithiumConcentration = cathodeInitialLithiumConcentration; }
void Param::setCathodeParticleRadius(double cathodeParticleRadius){ this->cathodeParticleRadius = cathodeParticleRadius; }
void Param::setCathodeDiffusionCoefficient(double cathodeDiffusionCoefficient){ this->cathodeDiffusionCoefficient = cathodeDiffusionCoefficient; }
void Param::setLiquidPhaseLithiumConcentration(double liquidPhaseLithiumConcentration){ this->liquidPhaseLithiumConcentration = liquidPhaseLithiumConcentration; }
void Param::setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential){ this->liquidPhaseLocalPotential = liquidPhaseLocalPotential; }
void Param::setTransferCoefficients(double transferCoefficients){ this->transferCoefficients = transferCoefficients; }
void Param::setTemperature(double temperature){ this->temperature = temperature; }
void Param::setAppliedCurrent(double appliedCurrent){ this->appliedCurrent = appliedCurrent; }
void Param::setSEILocalEquilibriumPotential(double SEILocalEquilibriumPotential){ this->SEILocalEquilibriumPotential = SEILocalEquilibriumPotential; }
void Param::setSEIElectronicConductivity(double SEIElectronicConductivity){ this->SEIElectronicConductivity = SEIElectronicConductivity; }
void Param::setSEIUnitArea(double SEIUnitArea){ this->SEIUnitArea = SEIUnitArea; }
void Param::setSEIUnitThickness(double SEIUnitThickness){ this->SEIUnitThickness = SEIUnitThickness; }
void Param::setUpperCutoffVoltage(double upperCutoffVoltage){ this->upperCutoffVoltage = upperCutoffVoltage;}
void Param::setLowerCutoffVoltage(double lowerCutoffVoltage){ this->lowerCutoffVoltage = lowerCutoffVoltage;}
void Param::setAdsorptionOneSideCoeff(double adsorptionOneSideCoeff){ this->adsorptionOneSideCoeff = adsorptionOneSideCoeff; }
void Param::setAdsorptionTwoSideCoeff(double adsorptionTwoSideCoeff){ this->adsorptionTwoSideCoeff = adsorptionTwoSideCoeff; }
void Param::setAdsorptionThreeSideCoeff(double adsorptionThreeSideCoeff){ this->adsorptionThreeSideCoeff = adsorptionThreeSideCoeff; }
void Param::setAdsorptionFourSideCoeff(double adsorptionFourSideCoeff){ this->adsorptionFourSideCoeff = adsorptionFourSideCoeff; }
void Param::setSPModelDeltaTime(double SPModelDeltaTime){ this->SPModelDeltaTime = SPModelDeltaTime; }
void Param::setKMCSurfaceSizeX(int KMCSurfaceSizeX){ this->KMCSurfaceSizeX = KMCSurfaceSizeX; }
void Param::setKMCSurfaceSizeY(int KMCSurfaceSizeY){ this->KMCSurfaceSizeY = KMCSurfaceSizeY; }
void Param::setMediatorEndCycles(int MediatorEndCycles){ this->MediatorEndCycles = MediatorEndCycles; }

double Param::getAnodeSurfaceArea(void){ return this->anodeSurfaceArea; }
double Param::getAnodeReactionRateConstant(void){ return this->anodeReactionRateConstant; }
double Param::getAnodeMaxLithiumConcentration(void){ return this->anodeMaxLithiumConcentration; }
double Param::getAnodeInitialLithiumConcentration(void){ return this->anodeInitialLithiumConcentration; }
double Param::getAnodeParticleRadius(void){ return this->anodeParticleRadius; }
double Param::getAnodeDiffusionCoefficient(void){ return this->anodeDiffusionCoefficient; }
double Param::getAnodeSideReactionExchangeCurrentDensity(void){ return this->anodeSideReactionExchangeCurrentDensity; }
double Param::getCathodeSurfaceArea(void){ return this->cathodeSurfaceArea; }
double Param::getCathodeReactionRateConstant(void){ return this->cathodeReactionRateConstant; }
double Param::getCathodeMaxLithiumConcentration(void){ return this->cathodeMaxLithiumConcentration; }
double Param::getCathodeInitialLithiumConcentration(void){ return this->cathodeInitialLithiumConcentration; }
double Param::getCathodeParticleRadius(void){ return this->cathodeParticleRadius; }
double Param::getCathodeDiffusionCoefficient(void){ return this->cathodeDiffusionCoefficient; }
double Param::getLiquidPhaseLithiumConcentration(void){ return this->liquidPhaseLithiumConcentration; }
double Param::getLiquidPhaseLocalPotential(void){ return this->liquidPhaseLocalPotential; }
double Param::getTransferCoefficients(void){ return this->transferCoefficients; }
double Param::getTemperature(void){ return this->temperature; }
double Param::getAppliedCurrent(void){ return this->appliedCurrent; }
double Param::getSEILocalEquilibriumPotential(void){return this->SEILocalEquilibriumPotential; }
double Param::getSEIElectronicConductivity(void){return this->SEIElectronicConductivity; }
double Param::getSEIUnitArea(void){ return this->SEIUnitArea; }
double Param::getSEIUnitThickness(void){ return this->SEIUnitThickness; }
double Param::getUpperCutoffVoltage(void){ return this->upperCutoffVoltage; }
double Param::getLowerCutoffVoltage(void){ return this->lowerCutoffVoltage; }
double Param::getAdsorptionOneSideCoeff(void){ return this->adsorptionOneSideCoeff; }
double Param::getAdsorptionTwoSideCoeff(void){ return this->adsorptionTwoSideCoeff; }
double Param::getAdsorptionThreeSideCoeff(void){ return this->adsorptionThreeSideCoeff; }
double Param::getAdsorptionFourSideCoeff(void){ return this->adsorptionFourSideCoeff; }
double Param::getSPModelDeltaTime(void){ return this->SPModelDeltaTime; }
int Param::getKMCSurfaceSizeX(void){ return this->KMCSurfaceSizeX; }
int Param::getKMCSurfaceSizeY(void){ return this->KMCSurfaceSizeY; }
int Param::getMediatorEndCycles(void){ return this->MediatorEndCycles; }


std::ostream &operator<<(std::ostream &out, Param &tgt){
    tgt.output(out);
    return out;
}
