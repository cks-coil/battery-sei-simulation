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
#include "sp_model.hpp"

using namespace std;

int main(void){
    srand((unsigned)time(NULL));

    State state;
    Param param;
    param.setAnodeSurfaceArea( 603.06 * pow(10,-6) );
    param.setAnodeReactionRateConstant( 4.854 * pow(10,-6) );
    param.setAnodeMaxLithiumConcentration( 30555 );
    param.setAnodeInitialLithiumConcentration( 0.03 * 30555 );
    param.setAnodeParticleRadius( 2 * pow(10,-6) );
    param.setAnodeDiffusionCoefficient( 3.9 * pow(10,-14) );
    param.setAnodeSideReactionExchangeCurrentDensity( 1.0 * pow(10,-7) );
    param.setCathodeSurfaceArea( 531.3 * pow(10,-6) );
    param.setCathodeReactionRateConstant( 2.252 * pow(10,-6) );
    param.setCathodeMaxLithiumConcentration( 51555 );
    param.setCathodeInitialLithiumConcentration( 0.95 * 51555 );
    param.setCathodeParticleRadius( 2 * pow(10,-6) );
    param.setCathodeDiffusionCoefficient( 1.0 * pow(10,-14) );
    param.setLiquidPhaseLithiumConcentration( 1000 );
    param.setLiquidPhaseLocalPotential( 0 );
    param.setTransferCoefficients( 0.5 );
    param.setTemperature( 298.15 );
    param.setAppliedCurrent( -2.9007*pow(10,-4) ); // \cks 1C
    param.setElectrolyteConductivity( pow(10,-2) );
    param.setUnitSEIArea( 4.964 * pow(10,-10) * 6.185 * pow(10,-10) / 2.0 );
    param.setUnitSEIThickness( 0.5 * 8.356 * pow(10,-10) * sin( 114.6 / 180.0 * M_PI ) );
    param.output(cout);

    SPModel sp(1);
    sp.setState(&state);
    sp.setParam(&param);
    state.output(cout);

    for(int i=0;i<500;i++){
        sp.step();
        cout << state.getCellVoltage() << endl;
    }
    for(int i=0;i<500;i++){
    param.setAppliedCurrent( 8.7020*pow(10,-4) *2 ); // \cks
        sp.step();
        cout << state.getCellVoltage() << endl;
    }


    return 0;
}
