/*
  \file    param.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_PARAM_HPP__
#define __INCLUDED_PARAM_HPP__


class Param{
public:
    Param(void);
    void setUnitDelta(double unitDelta);
    double getUnitDelta(void);
private:
    double unitDelta;
};

#endif

