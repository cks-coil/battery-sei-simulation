/*
  \File   transition.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "kmc_transition.hpp"

using namespace std;

KMCTransition::KMCTransition(void){
    surface = NULL;
    state = NULL;
    param = NULL;
    transitionRateSum = 0;
}

void KMCTransition::setSurface(KMCSurface *surface){
    this->surface = surface;
    initTransitionRateVector();
}
void KMCTransition::setState(State *state){
    this->state = state;
}
void KMCTransition::setParam(Param *param){
    this->param = param;
}
KMCSurface *KMCTransition::getSurface(void){
    return surface;
}
State *KMCTransition::getState(void){
    return state;
}
Param *KMCTransition::getParam(void){
    return param;
}

void KMCTransition::setTransitionRate(int n, double rate){
    transitionRate[n] = rate;
}
double KMCTransition::getTransitionRate(int n){
    return transitionRate[n];
}
double KMCTransition::getSumTransitionRate(void){
    return transitionRateSum;
}

int KMCTransition::getNumTransition(void){
    return (int)transitionRate.size();
}

void KMCTransition::transit(int n){}

void KMCTransition::updateState(void){}

void KMCTransition::calcTransitionRate(void){}

void KMCTransition::calcTransitionRateSum(void){
    double sum=0;
    for(int i=0;i<(int)transitionRate.size();i++) sum+= transitionRate[i];
    transitionRateSum = sum;
}

void KMCTransition::initTransitionRateVector(void){
    if(surface == NULL) return;
    int num = surface->getNumSite();
    transitionRate.clear();
    transitionRate.reserve(num);
    for(int i=0;i<num;i++) transitionRate.push_back(0);
}
