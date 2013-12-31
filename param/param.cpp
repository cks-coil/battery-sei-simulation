/*
  \file    param.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <math.h>
#include "constant.hpp"
#include "param.hpp"

Param::Param(void){
    unitDelta = 0;
}

void Param::setUnitDelta(double unitDelta){ this->unitDelta = unitDelta; }

double Param::getUnitDelta(void){ return this->unitDelta; }
