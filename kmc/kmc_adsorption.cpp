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
    State *s = getState();
    Param *p = getParam();

    for(int i=0; i<getNumTransition(); i++){
        if( getSurface()->isFlat(i) ){
            eta = s->getAnodeLocalPotential() - p->getLiquidPhaseLocalPotential() - p->getSEILocalEquilibriumPotential()
                - ( s->getAppliedCurrent() + s->getAnodeSideReactionCurrent() ) * getSurface()->getSEIThicknessPoint(i) / ( p->getAnodeSurfaceArea() * p->getSEIElectronicConductivity() );
            rate = p->getAnodeSideReactionExchangeCurrentDensity() * p->getSEIUnitArea() * constant::NA / constant::F
                * exp( - p->getTransferCoefficients() * constant::F / ( constant::R * p->getTemperature() ) * eta );
            setTransitionRate(i, rate*getSideCoeff( getSurface()->getNumSide(i)) );
        }else{
            setTransitionRate(i,0);
        }
    }
}

void KMCAdsorption::transit(int n){
    getSurface()->adsorb(n);
}

double KMCAdsorption::getSideCoeff(int sideNum){
    switch(sideNum){
    case 0: return 1.0;
    case 1: return getParam()->getAdsorptionOneSideCoeff();
    case 2: return getParam()->getAdsorptionTwoSideCoeff();
    case 3: return getParam()->getAdsorptionThreeSideCoeff();
    case 4: return getParam()->getAdsorptionFourSideCoeff();
    default: return 1.0;
    }
}
