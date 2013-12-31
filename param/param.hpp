/*
  \file    kmc_param.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>

  kmc param
*/

#ifndef __INCLUDED_KMC_PARAM_HPP__
#define __INCLUDED_KMC_PARAM_HPP__


class KMCParam{
public:
    KMCParam(void);
    void setUnitDelta(double unitDelta);
    double getUnitDelta(void);
private:
    double unitDelta;
};

#endif

