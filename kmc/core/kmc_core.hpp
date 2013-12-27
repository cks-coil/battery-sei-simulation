/*
  \file    kmc_core.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_CORE_HPP__
#define __INCLUDED_KMC_CORE_HPP__

#include <vector>
#include "kmc_state.hpp"
#include "kmc_transition.hpp"

class KMCCore{
public:
    KMCCore(void);
    void setState(KMCState *s);
    void setParam(KMCParam *p);
    void setTransition(KMCTransition *tr);
    void step(void);
    int getStepNum(void);
    double getTime(void);
private:
    int stepNum;
    double time;
    KMCState *st;
    KMCParam *p;
    std::vector<KMCTransition *> trs;
    double rateSum;
    void initTransition(int n);
    void initAllTransition(void);
    void initLastTransition(void);
    void calcRateSum(void);
    void transit(void);
    void updateTime(void);
};

#endif
