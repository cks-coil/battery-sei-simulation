/*
  \file    sp_model.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_SP_MODEL__
#define __INCLUDED_SP_MODEL__

#include "param.hpp"
#include "state.hpp"

class SPModel{
public:
    SPModel(double dt);
    void setState(State *s);
    void setParam(Param *p);
    void step(void);
    int getStepNum(void);
    double getTime(void);
private:
    double dt;
    double time;
    int stepNum;
    State *state;
    Param *param;
    void init(void);
};

#endif
