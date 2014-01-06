/*
  \File   transition.hpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_KMC_TRANSITION_HPP__
#define __INCLUDED_KMC_TRANSITION_HPP__

#include <vector>
#include "kmc_surface.hpp"
#include "param.hpp"

class KMCTransition{
public:
    KMCTransition(void);
    void setSurface(KMCSurface *st);
    void setParam(Param *p);
    KMCSurface *getSurface(void);
    Param *getParam(void);
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
    Param *p;
    double transitionRateSum;
    std::vector<double> transitionRate;
};

#endif
