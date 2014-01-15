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
    param.setAppliedCurrent( -2.9007*pow(10,-4)*0.2 ); // \cks 1C
    param.setSEILocalEquilibriumPotential( 0.4 );
    param.setSEIElectronicConductivity( 1.2*pow(10,-6) );
    param.setSEIUnitArea( 4.964 * pow(10,-10) * 6.185 * pow(10,-10) / 2.0 );
    param.setSEIUnitThickness( 0.5 * 8.356 * pow(10,-10) * sin( 114.6 / 180.0 * M_PI ) );
    param.output(cout);

    SPModel sp(10);
    sp.setState(&state);
    sp.setParam(&param);
    state.output(cout);

    KMCCore kmc;
    KMCSurface surface(100,100);
    KMCAdsorption adsorption;
    kmc.setParam(&param);
    kmc.setState(&state);
    kmc.setSurface(&surface);
    kmc.setTransition(&adsorption);

    for(int i=0; i<10; i++){
        int j=0;
        kmc.setTime(sp.getTime());
        while( state.getCellVoltage() <= 4.2 ){
            if( kmc.getTime() <= sp.getTime() ) kmc.step();
            else sp.step();
            if(i==1 || i==799) cout << j << " " << kmc.getStepNum() << " " << sp.getTime() << " " << kmc.getTime() << " " << state.getCellVoltage() << " " << state.getSEIThickness() << endl;
            j++;
        }
        param.setAppliedCurrent( -param.getAppliedCurrent() );
        kmc.setTime(sp.getTime());
        while( state.getCellVoltage() >= 3.0 ){
            if( kmc.getTime() <= sp.getTime() ) kmc.step();
            else sp.step();
            if(i==1 || i==799) cout << j << " " << kmc.getStepNum() << " " << sp.getTime() << " " << kmc.getTime() << " " << state.getCellVoltage() << " " << state.getSEIThickness() << endl;
            j--;
        }
        param.setAppliedCurrent( -param.getAppliedCurrent() );
        cout << i << " " << state.getSEIThickness() << " " << kmc.getStepNum() <<" #SEI" << endl;
    }

    return 0;
}
