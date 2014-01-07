/*
  \file   main.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
 */

#include <math.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "param.hpp"
#include "constant.hpp"
#include "kmc_core.hpp"
#include "kmc_surface.hpp"
#include "kmc_transition.hpp"
#include "kmc_adsorption.hpp"


int main(void){
    srand((unsigned)time(NULL));

    Param param;
    param.setTemperature(300);
    param.setUnitSEIThickness( 0.5 * 8.356 * pow(10,-10) * sin( 114.6 / 180.0 * M_PI ) );
    param.setUnitSEIArea( 4.964 * pow(10,-10) * 6.185 * pow(10,-10) / 2.0 );
    param.setElectrolyteConductivity( pow(10,-2) );
    param.setTransferCoefficients(0.5);
    param.setAnodeSpecificArea( 3.0 * (1.0 - 0.485) / (2 *pow(10,-6)) );
    param.setAnodeSideReactionExchangeCurrentDensity(1.0*pow(10,-11));

    return 0;
}
