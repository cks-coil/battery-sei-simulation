/*
  \file    param.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_PARAM_HPP__
#define __INCLUDED_PARAM_HPP__


class Param{
public:
    Param(void);
    void setUnitSEIThickness(double unitSEIThickness);
    double getUnitSEIThickness(void);
private:
    double unitSEIThickness; //  of one particle [m]
};

#endif

