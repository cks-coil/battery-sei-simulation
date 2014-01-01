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

double Param::getUnitSEIThickness(void){ return this->unitSEIThickness; }
