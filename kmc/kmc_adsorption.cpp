/*
  \file   kmc_adsorption.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <math.h>
#include "constant.hpp"
#include "kmc_adsorption.hpp"
#include "../param/param.hpp"
#include "../mediator/state.hpp"

KMCAdsorption::KMCAdsorption(void){}

void KMCAdsorption::calcTransitionRate(void){
    double eta;
    double rate;
    State *s = getState();
    Param *p = getParam();

    for(int i=0; i<getNumTransition(); i++){
        if( getSurface()->isFlat(i) ){
            eta = s->getAnodeLocalPotential() - p->getLiquidPhaseLocalPotential() - s->getAnodeLocalEquilibriumPotential()
                - ( p->getAppliedCurrent() + s->getAnodeSideReactionCurrent() ) * getSurface()->getSEIThicknessPoint(i) / ( p->getAnodeSurfaceArea() * p->getElectrolyteConductivity() );
            rate = p->getAnodeSideReactionExchangeCurrentDensity() / ( constant::F * p->getUnitSEIArea() )
                * exp( - p->getTransferCoefficients() * constant::F / ( constant::R * p->getTemperature() ) * eta );
            if( getSurface()->getNumSide(i) ) eta*=2;
            setTransitionRate(i,rate);
        }else{
            setTransitionRate(i,0);
        }
    }
}

void KMCAdsorption::transit(int n){
    getSurface()->adsorb(n);
}
