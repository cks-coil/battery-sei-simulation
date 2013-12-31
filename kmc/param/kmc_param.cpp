/*
  \file    kmc_param.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>

  kmc param
*/

#include <math.h>
#include "constant.hpp"
#include "kmc_param.hpp"

KMCParam::KMCParam(void){
    unitDelta = 0;
}

void KMCParam::setUnitDelta(double unitDelta){ this->unitDelta = unitDelta; }

double KMCParam::getUnitDelta(void){ return this->unitDelta; }
