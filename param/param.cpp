/*
  \file    param.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/
#include <math.h>
#include "constant.hpp"
#include "param.hpp"

Param::Param(void){
    unitSEIThickness = 0.0;
    temperature = 0.0;
    unitSEIThickness = 0.0;
    unitSEIArea = 0.0;
    electrolyteConductivity = 0.0;
    transferCoefficients = 0.0;
    anodeSpecificArea = 0.0;
    anodeSideReactionExchangeCurrentDensity = 0.0;
}

void Param::setTemperature(double temperature){ this->temperature = temperature; }
void Param::setUnitSEIThickness(double unitSEIThickness){ this->unitSEIThickness = unitSEIThickness; }
void Param::setUnitSEIArea(double unitSEIArea){ this->unitSEIArea = unitSEIArea; }
void Param::setElectrolyteConductivity(double electrolyteConductivity){ this->electrolyteConductivity = electrolyteConductivity; }
void Param::setTransferCoefficients(double transferCoefficients){ this->transferCoefficients = transferCoefficients; }
void Param::setAnodeSpecificArea(double anodeSpecificArea){ this->anodeSpecificArea = anodeSpecificArea; }
void Param::setAnodeSideReactionExchangeCurrentDensity(double anodeSideReactionExchangeCurrentDensity){ this->anodeSideReactionExchangeCurrentDensity = anodeSideReactionExchangeCurrentDensity; }

double Param::getTemperature(void){ return this->temperature; }
double Param::getUnitSEIThickness(void){ return this->unitSEIThickness; }
double Param::getUnitSEIArea(void){ return this->unitSEIArea; }
double Param::getElectrolyteConductivity(void){ return this->electrolyteConductivity; }
double Param::getTransferCoefficients(void){ return this->transferCoefficients; }
double Param::getAnodeSpecificArea(void){ return this->anodeSpecificArea; };
double Param::getAnodeSideReactionExchangeCurrentDensity(void){ return this->anodeSideReactionExchangeCurrentDensity; }
