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
    ECReductionPreFactorNoSide = 0;
    ECReductionPreFactorOneSide = 0;
    ECReductionPreFactorTwoSide = 0;
    ECReductionPreFactorThreeSide = 0;
    ECReductionPreFactorFourSide = 0;
    ECReorganizationEnergyNoSide = 0;
    ECReorganizationEnergyOneSide = 0;
    ECReorganizationEnergyTwoSide = 0;
    ECReorganizationEnergyThreeSide = 0;
    ECReorganizationEnergyFourSide = 0;
    ECReductionPotentialNoSide = 0;
    ECReductionPotentialOneSide = 0;
    ECReductionPotentialTwoSide = 0;
    ECReductionPotentialThreeSide = 0;
    ECReductionPotentialFourSide = 0;
    SEIElectronicConductivity = 0;
    SEIIonicConductivity = 0;
    SEIUnitArea = 0;
    SEIUnitThickness = 0;
    upperCutoffVoltage = 0;
    lowerCutoffVoltage = 0;
    SPModelDeltaTime = 0;
    KMCNullTransitionRate = 0;
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
        << "# ECReductionPreFactorNoSide: " << ECReductionPreFactorNoSide << std::endl
        << "# ECReductionPreFactorOneSide: " << ECReductionPreFactorOneSide << std::endl
        << "# ECReductionPreFactorTwoSide: " << ECReductionPreFactorTwoSide << std::endl
        << "# ECReductionPreFactorThreeSide: " << ECReductionPreFactorThreeSide << std::endl
        << "# ECReductionPreFactorFourSide: " << ECReductionPreFactorFourSide << std::endl
        << "# ECReorganizationEnergyNoSide: " << ECReorganizationEnergyNoSide << std::endl
        << "# ECReorganizationEnergyOneSide: " << ECReorganizationEnergyOneSide << std::endl
        << "# ECReorganizationEnergyTwoSide: " << ECReorganizationEnergyTwoSide << std::endl
        << "# ECReorganizationEnergyThreeSide: " << ECReorganizationEnergyThreeSide << std::endl
        << "# ECReorganizationEnergyFourSide: " << ECReorganizationEnergyFourSide << std::endl
        << "# ECReductionPotentialNoSide: " << ECReductionPotentialNoSide << std::endl
        << "# ECReductionPotentialOneSide: " << ECReductionPotentialOneSide << std::endl
        << "# ECReductionPotentialTwoSide: " << ECReductionPotentialTwoSide << std::endl
        << "# ECReductionPotentialThreeSide: " << ECReductionPotentialThreeSide << std::endl
        << "# ECReductionPotentialFourSide: " << ECReductionPotentialFourSide << std::endl
        << "# SEIElectronicConductivity: " << SEIElectronicConductivity << std::endl
        << "# SEIIonicConductivity: " << SEIIonicConductivity << std::endl
        << "# SEIUnitArea: " << SEIUnitArea << std::endl
        << "# SEIUnitThickness: " << SEIUnitThickness << std::endl
        << "# upperCutoffVoltage: " << upperCutoffVoltage << std::endl
        << "# lowerCutoffVoltage: " << lowerCutoffVoltage << std::endl
        << "# SPModelDeltaTime: " << SPModelDeltaTime << std::endl
        << "# KMCNullTransitionRate: " << KMCNullTransitionRate << std::endl
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
void Param::setECReductionPreFactorNoSide(double ECReductionPreFactorNoSide){ this->ECReductionPreFactorNoSide = ECReductionPreFactorNoSide; }
void Param::setECReductionPreFactorOneSide(double ECReductionPreFactorOneSide){ this->ECReductionPreFactorOneSide = ECReductionPreFactorOneSide; }
void Param::setECReductionPreFactorTwoSide(double ECReductionPreFactorTwoSide){ this->ECReductionPreFactorTwoSide = ECReductionPreFactorTwoSide; }
void Param::setECReductionPreFactorThreeSide(double ECReductionPreFactorThreeSide){ this->ECReductionPreFactorThreeSide = ECReductionPreFactorThreeSide; }
void Param::setECReductionPreFactorFourSide(double ECReductionPreFactorFourSide){ this->ECReductionPreFactorFourSide = ECReductionPreFactorFourSide; }
void Param::setECReorganizationEnergyNoSide(double ECReorganizationEnergyNoSide){ this->ECReorganizationEnergyNoSide = ECReorganizationEnergyNoSide; }
void Param::setECReorganizationEnergyOneSide(double ECReorganizationEnergyOneSide){ this->ECReorganizationEnergyOneSide = ECReorganizationEnergyOneSide; }
void Param::setECReorganizationEnergyTwoSide(double ECReorganizationEnergyTwoSide){ this->ECReorganizationEnergyTwoSide = ECReorganizationEnergyTwoSide; }
void Param::setECReorganizationEnergyThreeSide(double ECReorganizationEnergyThreeSide){ this->ECReorganizationEnergyThreeSide = ECReorganizationEnergyThreeSide; }
void Param::setECReorganizationEnergyFourSide(double ECReorganizationEnergyFourSide){ this->ECReorganizationEnergyFourSide = ECReorganizationEnergyFourSide; }
void Param::setECReductionPotentialNoSide(double ECReductionPotentialNoSide){ this->ECReductionPotentialNoSide = ECReductionPotentialNoSide; }
void Param::setECReductionPotentialOneSide(double ECReductionPotentialOneSide){ this->ECReductionPotentialOneSide = ECReductionPotentialOneSide; }
void Param::setECReductionPotentialTwoSide(double ECReductionPotentialTwoSide){ this->ECReductionPotentialTwoSide = ECReductionPotentialTwoSide; }
void Param::setECReductionPotentialThreeSide(double ECReductionPotentialThreeSide){ this->ECReductionPotentialThreeSide = ECReductionPotentialThreeSide; }
void Param::setECReductionPotentialFourSide(double ECReductionPotentialFourSide){ this->ECReductionPotentialFourSide = ECReductionPotentialFourSide; }
void Param::setSEIElectronicConductivity(double SEIElectronicConductivity){ this->SEIElectronicConductivity = SEIElectronicConductivity; }
void Param::setSEIIonicConductivity(double SEIIonicConductivity){ this->SEIIonicConductivity = SEIIonicConductivity; }
void Param::setSEIUnitArea(double SEIUnitArea){ this->SEIUnitArea = SEIUnitArea; }
void Param::setSEIUnitThickness(double SEIUnitThickness){ this->SEIUnitThickness = SEIUnitThickness; }
void Param::setUpperCutoffVoltage(double upperCutoffVoltage){ this->upperCutoffVoltage = upperCutoffVoltage;}
void Param::setLowerCutoffVoltage(double lowerCutoffVoltage){ this->lowerCutoffVoltage = lowerCutoffVoltage;}
void Param::setSPModelDeltaTime(double SPModelDeltaTime){ this->SPModelDeltaTime = SPModelDeltaTime; }
void Param::setKMCNullTransitionRate(double KMCNullTransitionRate){ this->KMCNullTransitionRate = KMCNullTransitionRate; }
void Param::setKMCSurfaceSizeX(int KMCSurfaceSizeX){ this->KMCSurfaceSizeX = KMCSurfaceSizeX; }
void Param::setKMCSurfaceSizeY(int KMCSurfaceSizeY){ this->KMCSurfaceSizeY = KMCSurfaceSizeY; }
void Param::setMediatorEndCycles(int MediatorEndCycles){ this->MediatorEndCycles = MediatorEndCycles; }

double Param::getAnodeSurfaceArea(void){ return this->anodeSurfaceArea; }
double Param::getAnodeReactionRateConstant(void){ return this->anodeReactionRateConstant; }
double Param::getAnodeMaxLithiumConcentration(void){ return this->anodeMaxLithiumConcentration; }
double Param::getAnodeInitialLithiumConcentration(void){ return this->anodeInitialLithiumConcentration; }
double Param::getAnodeParticleRadius(void){ return this->anodeParticleRadius; }
double Param::getAnodeDiffusionCoefficient(void){ return this->anodeDiffusionCoefficient; }
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
double Param::getECReductionPreFactorNoSide(void){ return this->ECReductionPreFactorNoSide; }
double Param::getECReductionPreFactorOneSide(void){ return this->ECReductionPreFactorOneSide; }
double Param::getECReductionPreFactorTwoSide(void){ return this->ECReductionPreFactorTwoSide; }
double Param::getECReductionPreFactorThreeSide(void){ return this->ECReductionPreFactorThreeSide; }
double Param::getECReductionPreFactorFourSide(void){ return this->ECReductionPreFactorFourSide; }
double Param::getECReorganizationEnergyNoSide(void){ return this->ECReorganizationEnergyNoSide; }
double Param::getECReorganizationEnergyOneSide(void){ return this->ECReorganizationEnergyOneSide; }
double Param::getECReorganizationEnergyTwoSide(void){ return this->ECReorganizationEnergyTwoSide; }
double Param::getECReorganizationEnergyThreeSide(void){ return this->ECReorganizationEnergyThreeSide; }
double Param::getECReorganizationEnergyFourSide(void){ return this->ECReorganizationEnergyFourSide; }
double Param::getECReductionPotentialNoSide(void){ return this->ECReductionPotentialNoSide; }
double Param::getECReductionPotentialOneSide(void){ return this->ECReductionPotentialOneSide; }
double Param::getECReductionPotentialTwoSide(void){ return this->ECReductionPotentialTwoSide; }
double Param::getECReductionPotentialThreeSide(void){ return this->ECReductionPotentialThreeSide; }
double Param::getECReductionPotentialFourSide(void){ return this->ECReductionPotentialFourSide; }
double Param::getSEIElectronicConductivity(void){return this->SEIElectronicConductivity; }
double Param::getSEIIonicConductivity(void){return this->SEIIonicConductivity; }
double Param::getSEIUnitArea(void){ return this->SEIUnitArea; }
double Param::getSEIUnitThickness(void){ return this->SEIUnitThickness; }
double Param::getUpperCutoffVoltage(void){ return this->upperCutoffVoltage; }
double Param::getLowerCutoffVoltage(void){ return this->lowerCutoffVoltage; }
double Param::getSPModelDeltaTime(void){ return this->SPModelDeltaTime; }
double Param::getKMCNullTransitionRate(void){ return this->KMCNullTransitionRate; }
int Param::getKMCSurfaceSizeX(void){ return this->KMCSurfaceSizeX; }
int Param::getKMCSurfaceSizeY(void){ return this->KMCSurfaceSizeY; }
int Param::getMediatorEndCycles(void){ return this->MediatorEndCycles; }


std::ostream &operator<<(std::ostream &out, Param &tgt){
    tgt.output(out);
    return out;
}
