/*
  \file    kmc_core.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_CORE_HPP__
#define __INCLUDED_KMC_CORE_HPP__

#include <vector>
#include <random>
#include "param.hpp"
#include "state.hpp"
#include "kmc_surface.hpp"
#include "kmc_transition.hpp"


class KMCCore{
public:
    KMCCore(void);
    ~KMCCore(void);
    void setSurface(KMCSurface *surface);
    void setState(State *state);
    void setParam(Param *param);
    void setTransition(KMCTransition *tr);
    void step(void);
    void endCycle(double time);
    void startCycle(void);
    int getStepNum(void);
    double getTime(void);
private:
    std::mt19937 *engine;
    std::uniform_real_distribution<double> *rnd;
    int stepNum;
    double time;
    KMCSurface *surface;
    State *state;
    Param *param;
    std::vector<KMCTransition *> trs;
    double rateSum;
    KMCTransition *lastTrs;
    double lastDeltaT;
    int lastN;
    bool skipFlag;
    void initTransition(int n);
    void initAllTransition(void);
    void initLastTransition(void);
    void initSurface(void);
    void transit(void);
    void updateTime(void);
};

#endif
