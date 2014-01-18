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
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() ) outputLog("#StepLog #Charge #KMC");
        }else{
            sp->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() ) outputLog("#StepLog #Charge #SPModel");
        }
    }
}
void Mediator::discharge(void){
    state->setAppliedCurrent( param->getAppliedCurrent() );
    sp->startCycle();
    kmc->startCycle();
    while( state->getCellVoltage() >= param->getLowerCutoffVoltage() ){
        if( kmc->getTime() <= sp->getTime() ){
            kmc->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() ) outputLog("#StepLog #Discharge #KMC");
        }else{
            sp->step();
            if( currentCycles==1 || currentCycles==param->getMediatorEndCycles() ) outputLog("#StepLog #Discharge #SPModel");
        }
    }
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
