/*
  \file   kmc_adsorption.hpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_ADSORPTION_HPP__
#define __INCLUDED_KMC_ADSORPTION_HPP__

#include "kmc_transition.hpp"

class KMCAdsorption : public KMCTransition{
public:
    KMCAdsorption(void);
    void updateState(void);
    void calcTransitionRate(void);
    void transit(int n);
private:
};

#endif
