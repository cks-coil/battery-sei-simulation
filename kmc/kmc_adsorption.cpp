/*
  \file   kmc_adsorption.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <math.h>
#include "constant.hpp"
#include "kmc_adsorption.hpp"

KMCAdsorption::KMCAdsorption(void){}

void KMCAdsorption::updateState(void){
    double current;
    current = getSumTransitionRate() * getParam()->getAnodeSurfaceArea() * constant::F / ( constant::NA * getSurface()->getSurfaceArea() );
    getState()->setAnodeSideReactionCurrent( current );
}

void KMCAdsorption::calcTransitionRate(void){
    double eta;
    double rate;
    double sideCoeff;
    State *s = getState();
    Param *p = getParam();

    for(int i=0; i<getNumTransition(); i++){
        if( getSurface()->isFlat(i) ){
            eta = s->getAnodeLocalPotential() - p->getLiquidPhaseLocalPotential() - p->getSEILocalEquilibriumPotential()
                - ( p->getAppliedCurrent() + s->getAnodeSideReactionCurrent() ) * getSurface()->getSEIThicknessPoint(i) / ( p->getAnodeSurfaceArea() * p->getSEIElectronicConductivity() );
            rate = p->getAnodeSideReactionExchangeCurrentDensity() * p->getSEIUnitArea() * constant::NA / constant::F
                * exp( - p->getTransferCoefficients() * constant::F / ( constant::R * p->getTemperature() ) * eta );
            if( getSurface()->getNumSide(i) ) sideCoeff = 2;
            else sideCoeff = 1;
            setTransitionRate(i,rate*sideCoeff);
        }else{
            setTransitionRate(i,0);
        }
    }
}

void KMCAdsorption::transit(int n){
    getSurface()->adsorb(n);
}
