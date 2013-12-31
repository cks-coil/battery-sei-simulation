/*
  \File   transition.hpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_TRANSITION_HPP__
#define __INCLUDED_KMC_TRANSITION_HPP__

#include <vector>
#include "kmc_surface.hpp"
#include "kmc_param.hpp"

class Transition{
public:
    Transition(void);
    void setSurface(KMCSurface *st);
    void setParam(KMCParam *p);
    KMCSurface *getSurface(void);
    KMCParam *getParam(void);
    void setTransitionRate(int n, double rate);
    double getTransitionRate(int n);
    double getSumTransitionRate(void);
    int getNumTransition(void);
    virtual void transit(int n);
    virtual void calcTransitionRate(void);
    void calcTransitionRateSum(void);
private:
    void initTransitionRateVector(void);
    KMCSurface *s;
    KMCParam *p;
    double transitionRateSum;
    std::vector<double> transitionRate;
};

#endif
