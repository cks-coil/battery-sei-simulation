/*
  \file    kmc_core.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_CORE_HPP__
#define __INCLUDED_KMC_CORE_HPP__

#include <vector>
#include "kmc_surface.hpp"
#include "kmc_transition.hpp"

class KMCCore{
public:
    KMCCore(void);
    void setSurface(KMCSurface *s);
    void setParam(Param *p);
    void setTransition(KMCTransition *tr);
    void step(void);
    int getStepNum(void);
    double getTime(void);
private:
    int stepNum;
    double time;
    KMCSurface *s;
    Param *p;
    std::vector<KMCTransition *> trs;
    double rateSum;
    void initTransition(int n);
    void initAllTransition(void);
    void initLastTransition(void);
    void transit(void);
    void updateTime(void);
};

#endif
