/*
  \file    kmc_null_transition.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "kmc_null_transition.hpp"
#include "param.hpp"

KMCNullTransition::KMCNullTransition(void){}

void KMCNullTransition::calcTransitionRate(void){
    for(int i=0; i<getNumTransition(); i++) setTransitionRate(i, getParam()->getKMCNullTransitionRate());
}
