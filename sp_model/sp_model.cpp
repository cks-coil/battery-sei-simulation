/*
  \file    sp_model.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "sp_model.hpp"

SPModel::SPModel(double dt){
    this->dt = dt;
    this->time = 0;
    this->stepNum = 0;
    this->p = NULL;
    this->s = NULL;
}

void SPModel::setState(State *s){
    this->s = s;
    init();
}
void SPModel::setParam(Param *p){
    this->p = p;
    init();
}

void SPModel::step(void){
    // \cks
}

int SPModel::getStepNum(void){ return stepNum; }
double SPModel::getTime(void){ return time; }

void SPModel::init(void){
    if( p==NULL || s==NULL ) return;
    // \cks
}
