/*
  \file   kmc_adsorption.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "kmc_adsorption.hpp"

KMCAdsorption(void){} // \cks

void KMCAdsorption::calcTransitionRate(void){
}

void KMCAdsorption::transit(int n){
    getSurface()->adsorb(n);
}
