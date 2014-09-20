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
    int sideNum;

    for(int i=0; i<getNumTransition(); i++){
        if( getSurface()->isFlat(i) ){
            sideNum = getSurface()->getNumSideUp(i);
            deltaGo = s->getAnodeLocalPotential() - p->getLiquidPhaseLocalPotential() - getECReductionPotential(sideNum)
                - ( ( s->getAppliedCurrent() - s->getAnodeSideReactionCurrent() ) / p->getSEIIonicConductivity() + s->getAnodeSideReactionCurrent() / p->getSEIElectronicConductivity() )
                * getSurface()->getSEIThicknessPoint(i) / p->getAnodeSurfaceArea();
            rate = getECReductionPreFactor(sideNum) * p->getSEIUnitArea() * constant::NA / ( 2 * constant::F )
                * exp( - pow( (getECReorganizationEnergy(sideNum) + deltaGo), 2 ) / (4 * getECReorganizationEnergy(sideNum) * constant::kB * p->getTemperature()) );
            setTransitionRate(i, rate);

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

double KMCAdsorption::getECReductionPreFactor(int sideNum){
    switch(sideNum){
    case 0: return getParam()->getECReductionPreFactorNoSide();
    case 1: return getParam()->getECReductionPreFactorOneSide();
    case 2: return getParam()->getECReductionPreFactorTwoSide();
    case 3: return getParam()->getECReductionPreFactorThreeSide();
    case 4: return getParam()->getECReductionPreFactorFourSide();
    default: return 0.0;
    }
}
double KMCAdsorption::getECReorganizationEnergy(int sideNum){
    switch(sideNum){
    case 0: return getParam()->getECReorganizationEnergyNoSide();
    case 1: return getParam()->getECReorganizationEnergyOneSide();
    case 2: return getParam()->getECReorganizationEnergyTwoSide();
    case 3: return getParam()->getECReorganizationEnergyThreeSide();
    case 4: return getParam()->getECReorganizationEnergyFourSide();
    default: return 0.0;
    }
}
double KMCAdsorption::getECReductionPotential(int sideNum){
    switch(sideNum){
    case 0: return getParam()->getECReductionPotentialNoSide();
    case 1: return getParam()->getECReductionPotentialOneSide();
    case 2: return getParam()->getECReductionPotentialTwoSide();
    case 3: return getParam()->getECReductionPotentialThreeSide();
    case 4: return getParam()->getECReductionPotentialFourSide();
    default: return 0.0;
    }
}
