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
    anodeParticleRadius = 0;
    anodeDiffusionCoefficient = 0;
    anodeSideReactionExchangeCurrentDensity = 0;
    cathodeSurfaceArea = 0;
    cathodeReactionRateConstant = 0;
    cathodeMaxLithiumConcentration = 0;
    cathodeParticleRadius = 0;
    cathodeDiffusionCoefficient = 0;
    liquidPhaseLocalConcentration = 0;
    liquidPhaseLocalPotential = 0;
    transferCoefficients = 0;
    temperature = 0;
    appliedCurrent = 0;
}

void Param::setAnodeSurfaceArea(double anodeSurfaceArea){ this->anodeSurfaceArea = anodeSurfaceArea; }
void Param::setAnodeReactionRateConstant(double anodeReactionRateConstant){ this->anodeReactionRateConstant = anodeReactionRateConstant; }
void Param::setAnodeMaxLithiumConcentration(double anodeMaxLithiumConcentration){ this->anodeMaxLithiumConcentration = anodeMaxLithiumConcentration; }
void Param::setAnodeParticleRadius(double anodeParticleRadius){ this->anodeParticleRadius = anodeParticleRadius; }
void Param::setAnodeDiffusionCoefficient(double anodeDiffusionCoefficient){ this->anodeDiffusionCoefficient = anodeDiffusionCoefficient; }
void Param::setAnodeSideReactionExchangeCurrentDensity(double anodeSideReactionExchangeCurrentDensity){ this->anodeSideReactionExchangeCurrentDensity = anodeSideReactionExchangeCurrentDensity; }
void Param::setCathodeSurfaceArea(double cathodeSurfaceArea){ this->cathodeSurfaceArea = cathodeSurfaceArea; }
void Param::setCathodeReactionRateConstant(double cathodeReactionRateConstant){ this->cathodeReactionRateConstant = cathodeReactionRateConstant; }
void Param::setCathodeMaxLithiumConcentration(double cathodeMaxLithiumConcentration){ this->cathodeMaxLithiumConcentration = cathodeMaxLithiumConcentration; }
void Param::setCathodeParticleRadius(double cathodeParticleRadius){ this->cathodeParticleRadius = cathodeParticleRadius; }
void Param::setCathodeDiffusionCoefficient(double cathodeDiffusionCoefficient){ this->cathodeDiffusionCoefficient = cathodeDiffusionCoefficient; }
void Param::setLiquidPhaseLocalConcentration(double liquidPhaseLocalConcentration){ this->liquidPhaseLocalConcentration = liquidPhaseLocalConcentration; }
void Param::setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential){ this->liquidPhaseLocalPotential = liquidPhaseLocalPotential; }
void Param::setTransferCoefficients(double transferCoefficients){ this->transferCoefficients = transferCoefficients; }
void Param::setTemperature(double temperature){ this->temperature = temperature; }
void Param::setAppliedCurrent(double appliedCurrent){ this->appliedCurrent = appliedCurrent; }
void Param::setUnitSEIArea(double unitSEIArea){ this->unitSEIArea = unitSEIArea; }
void Param::setUnitSEIThickness(double unitSEIThickness){ this->unitSEIThickness = unitSEIThickness; }

double Param::getAnodeSurfaceArea(void){ return this->anodeSurfaceArea; }
double Param::getAnodeReactionRateConstant(void){ return this->anodeReactionRateConstant; }
double Param::getAnodeMaxLithiumConcentration(void){ return this->anodeMaxLithiumConcentration; }
double Param::getAnodeParticleRadius(void){ return this->anodeParticleRadius; }
double Param::getAnodeDiffusionCoefficient(void){ return this->anodeDiffusionCoefficient; }
double Param::getAnodeSideReactionExchangeCurrentDensity(void){ return this->anodeSideReactionExchangeCurrentDensity; }
double Param::getCathodeSurfaceArea(void){ return this->cathodeSurfaceArea; }
double Param::getCathodeReactionRateConstant(void){ return this->cathodeReactionRateConstant; }
double Param::getCathodeMaxLithiumConcentration(void){ return this->cathodeMaxLithiumConcentration; }
double Param::getCathodeParticleRadius(void){ return this->cathodeParticleRadius; }
double Param::getCathodeDiffusionCoefficient(void){ return this->cathodeDiffusionCoefficient; }
double Param::getLiquidPhaseLocalConcentration(void){ return this->liquidPhaseLocalConcentration; }
double Param::getLiquidPhaseLocalPotential(void){ return this->liquidPhaseLocalPotential; }
double Param::getTransferCoefficients(void){ return this->transferCoefficients; }
double Param::getTemperature(void){ return this->temperature; }
double Param::getAppliedCurrent(void){ return this->appliedCurrent; }
double Param::getUnitSEIArea(void){ return this->unitSEIArea; }
double Param::getUnitSEIThickness(void){ return this->unitSEIThickness; }

