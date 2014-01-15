/*
  \file    kmc_core.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <math.h>
#include <stdlib.h>
#include "kmc_core.hpp"

using namespace std;

KMCCore::KMCCore(void){
    stepNum = 0;
    time = 0;
    surface = NULL;
    state = NULL;
    param = NULL;
    trs.clear();
    rateSum = 0;
}

void KMCCore::setSurface(KMCSurface *surface){
    this->surface = surface;
    initAllTransition();
    initSurface();
}
void KMCCore::setState(State *state){
    this->state = state;
    initAllTransition();
    initSurface();
}
void KMCCore::setParam(Param *param){
    this->param = param;
    initAllTransition();
    initSurface();
}

void KMCCore::setTransition(KMCTransition *tr){
    trs.push_back(tr);
    initLastTransition();
    initSurface();
}

void KMCCore::step(void){
    int i;
    stepNum++;
    rateSum = 0;
    for(i=0; i<(int)trs.size(); i++){
        trs[i]->calcTransitionRate();
        trs[i]->calcTransitionRateSum();
        rateSum += trs[i]->getSumTransitionRate();
    }
    transit();
    for(i=0; i<(int)trs.size(); i++) trs[i]->updateState();
    surface->updateState();
    updateTime();
}

int KMCCore::getStepNum(void){ return stepNum; }
double KMCCore::getTime(void){ return time; }
void KMCCore::setTime(double time){ this->time = time; }

void KMCCore::initTransition(int n){
    if(surface == NULL || param == NULL || state == NULL) return;
    trs[n]->setSurface(surface);
    trs[n]->setState(state);
    trs[n]->setParam(param);
}
void KMCCore::initAllTransition(void){
    for(int i=0; i<(int)trs.size(); i++) initTransition(i);
}
void KMCCore::initLastTransition(void){
    initTransition((int)trs.size()-1);
}

void KMCCore::initSurface(void){
    if(surface == NULL || param == NULL || state == NULL) return;
    surface->setParam(param);
    surface->setState(state);
    surface->updateState();
}

// Equ.13
void KMCCore::transit(void){
    double xi = (double)rand() / (double)RAND_MAX;
    int i=0, j=0;
    double tmp;
    double sum;

    // 例外処理 \cks updateTimeと同じ例外処理をするべきか
    if(xi == 1.0){
        trs.back()->transit(trs.back()->getNumTransition()-1);
        return;
    }

    // Sigma_{k=0}^{i} trs[k]->getSumTransitionRate() > xi となる最小のiを探す
    // sum = Sigma_{k=0}^{i-1} trs[k]->getSumTransitionRate() <= xi
    // よって、trs[i]->getSumTransitionRate() != 0
    sum = 0;
    tmp = trs[0]->getSumTransitionRate();
    for(; i<((int)trs.size()-1) && tmp/rateSum <= xi; i++){
        sum = tmp;
        tmp += trs[i+1]->getSumTransitionRate();
    }

    // sum + Sigma_{k=0}^{j-1} trs[i]->getTransitionRate(k) > xi となる最小のjを探す
    // Sigma_{k=0}^{i-1} trs[k]->getSumTransitionRate() + Sigma_{k=0}^{j-1} trs[k]->getTransitionRate(k) <= xi
    // よって、trs[i]->getTransitionRate(j) != 0
    tmp = trs[i]->getTransitionRate(0);
    for(; j<(trs[i]->getNumTransition()-1) && (tmp+sum)/rateSum <= xi; j++){
        tmp += trs[i]->getTransitionRate(j+1);
    }

    // 多分起こらないはずだが一応チェック(積算誤差で起こるかも)
    if(trs[i]->getTransitionRate(j) == 0 ){
        while( j>0 && trs[i]->getTransitionRate(j)==0.0 ) j--;
        while( j<trs[i]->getNumTransition()-1 && trs[i]->getTransitionRate(j)==0.0) j++;
        // \cks error output
    }

    trs[i]->transit(j);
}


void KMCCore::updateTime(void){
    double xi=0.0;
    double deltaT;
    
    // xi->0 log(xi) -> -inf 
    while(xi == 0.0) xi = (double)rand() / (double)RAND_MAX;
    
    deltaT = - log(xi) / rateSum; // Equ.14
    time += deltaT;
}
