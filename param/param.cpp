/*
  \file    param.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <math.h>
#include "constant.hpp"
#include "param.hpp"

Param::Param(void){
    unitSEIThickness = 0;
}

void Param::setUnitSEIThickness(double unitSEIThickness){ this->unitSEIThickness = unitSEIThickness; }
void Param::setUnitSEIArea(double unitSEIArea){ this->unitSEIArea = unitSEIArea; }
void Param::setElectrolyteConductivity(double electrolyteConductivity){ this->electrolyteConductivity = electrolyteConductivity; }
void Param::setTransferCoefficients(double transferCoefficients){ this->transferCoefficients = transferCoefficients; }


double Param::getUnitSEIThickness(void){ return this->unitSEIThickness; }
double Param::getUnitSEIArea(void){ return this->unitSEIArea; }
double Param::getElectrolyteConductivity(void){ return this->electrolyteConductivity; }
double Param::getTransferCoefficients(void){ return this->transferCoefficients; }
