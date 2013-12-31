/*
  \File   transition.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "transition.hpp"

using namespace std;

KMCTransition::Transition(void){
    s = NULL;
    p = NULL;
    transitionRateSum = 0;
}

void KMCTransition::setSurface(KMCSurface *s){
    this->s = s;
    initTransitionRateVector();
}
void KMCTransition::setParam(KMCParam *p){
    this->p = p;
}
KMCSurface *KMCTransition::getSurface(void){
    return s;
}
KMCParam *KMCTransition::getParam(void){
    return p;
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

void KMCTransition::calcTransitionRate(void){}

void KMCTransition::calcTransitionRateSum(void){
    double sum=0;
    for(int i=0;i<(int)transitionRate.size();i++) sum+= transitionRate[i];
    transitionRateSum = sum;
}

void KMCTransition::initTransitionRateVector(void){
    if(s == NULL) return;
    int num = surface->getNumSite();
    transitionRate.clear();
    transitionRate.reserve(num);
    for(int i=0;i<num;i++) transitionRate.push_back(0);
}
