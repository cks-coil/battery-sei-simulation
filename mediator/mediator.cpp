/*
  \file   mediator->cpp
  \author Chikashi Shinagawa <shinagawa@tcl->t->u-tokyo->ac->jp>
*/

#include <stdlib.h>
#include <iostream>
#include "mediator.hpp"

using namespace std;

Mediator::Mediator(void){
    param = NULL;
    state = NULL;
    kmc = NULL;
    sp = NULL;
    stream = &(std::cout);
}

void Mediator::setParam(Param *param){ this->param = param; }
void Mediator::setState(State *state){ this->state = state; }
void Mediator::setSPModel(SPModel *sp){ this->sp = sp; }
void Mediator::setKMC(KMCCore *kmc){ this->kmc = kmc; }
void Mediator::setSurface(KMCSurface *surface){ this->surface = surface; }
void Mediator::setStream(ostream &stream){ this->stream = &(stream); }

void Mediator::run(void){
    preCharge();
    preDisCharge();
    currentCycles = 1;
    for(; currentCycles<=param->getMediatorEndCycles(); currentCycles++){
        charge();
        outputLog("#CycleLog #Charge");
        discharge();
        outputLog("#CycleLog #Discharge");
        if( currentCycles==1 ) outputSurface("#Surface #Discharge #First");
        else if( currentCycles==param->getMediatorEndCycles()/2 ) outputSurface("#Surface #Discharge #Half");
        else if( currentCycles==param->getMediatorEndCycles() ) outputSurface("#Surface #Discharge #Last");
    }
}

void Mediator::preCharge(void){
    state->setAppliedCurrent( - param->getAppliedCurrent() );
    sp->startCycle();
    while( state->getCellVoltage() <= param->getUpperCutoffVoltage() ) sp->step();
}
void Mediator::preDisCharge(void){
    state->setAppliedCurrent( param->getAppliedCurrent() );
    sp->startCycle();
    while( state->getCellVoltage() >= param->getLowerCutoffVoltage() ) sp->step();
}

void Mediator::charge(void){
    state->setAppliedCurrent( - param->getAppliedCurrent() );
    sp->startCycle();
    kmc->startCycle();
    while( state->getCellVoltage() <= param->getUpperCutoffVoltage() ){
        if( kmc->getTime() <= sp->getTime() ){
            kmc->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() || currentCycles==param->getMediatorEndCycles()/2 ) outputLog("#StepLog #Charge #KMC");
        }else{
            sp->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() || currentCycles==param->getMediatorEndCycles()/2 ) outputLog("#StepLog #Charge #SPModel");
        }
    }
    kmc->endCycle(sp->getTime());
}
void Mediator::discharge(void){
    state->setAppliedCurrent( param->getAppliedCurrent() );
    sp->startCycle();
    kmc->startCycle();
    while( state->getCellVoltage() >= param->getLowerCutoffVoltage() ){
        if( kmc->getTime() <= sp->getTime() ){
            kmc->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() || currentCycles==param->getMediatorEndCycles()/2 ) outputLog("#StepLog #Discharge #KMC");
        }else{
            sp->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() || currentCycles==param->getMediatorEndCycles()/2 ) outputLog("#StepLog #Discharge #SPModel");
        }
    }
    kmc->endCycle(sp->getTime());
}

void Mediator::outputLog(string label){
    *stream << currentCycles << " "
            << sp->getTime() << " "
            << sp->getStepNum() << " "
            << kmc->getTime() << " "
            << kmc->getStepNum() << " "
            << *state << " "
            << label << endl;
}

void Mediator::outputSurface(string label){
    *stream << *surface << label << endl;
}
