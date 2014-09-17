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
    current = - 2 * getSumTransitionRate() * getParam()->getAnodeSurfaceArea() * constant::F / ( constant::NA * getSurface()->getSurfaceArea() );
    getState()->setAnodeSideReactionCurrent( current );
}

void KMCAdsorption::calcTransitionRate(void){
    double deltaGo;
    double rate;
    State *s = getState();
    Param *p = getParam();

    for(int i=0; i<getNumTransition(); i++){
        if( getSurface()->isFlat(i) ){
            deltaGo = s->getAnodeLocalPotential() - p-> getLiquidPhaseLocalPotential() - p->getECReductionPotential()
                - ( ( s->getAppliedCurrent() - s->getAnodeSideReactionCurrent() ) / p->getSEIIonicConductivity() + s->getAnodeSideReactionCurrent() / p->getSEIElectronicConductivity() )
                * getSurface()->getSEIThicknessPoint(i) / p->getAnodeSurfaceArea();
            rate = p->getECReductionPreFactor() * p->getSEIUnitArea() * constant::NA / ( 2 * constant::F )
                * exp( - pow( (p->getECReorganizationEnergy() + deltaGo), 2 ) / (4 * p->getECReorganizationEnergy() * constant::kB * p->getTemperature()) );
            setTransitionRate(i, rate*getSideCoeff( getSurface()->getNumSideUp(i)) );

        }else{
            setTransitionRate(i,0);
        }
    }
}

void KMCAdsorption::transit(int n){
    getSurface()->adsorb(n);
}
void KMCAdsorption::restore(int n){
    getSurface()->desorb(n);
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
