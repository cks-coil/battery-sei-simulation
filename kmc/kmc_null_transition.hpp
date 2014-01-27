/*
  \file    kmc_null_transition.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_NULL_TRANSITION__
#define __INCLUDED_KMC_NULL_TRANSITION__

#include "kmc_transition.hpp"

class KMCNullTransition: public KMCTransition{
public:
    KMCNullTransition(void);
    void calcTransitionRate(void);
};

#endif
