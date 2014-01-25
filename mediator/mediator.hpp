/*
  \file   mediator.hpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_MEDIATOR_HPP__
#define __INCLUDED_MEDIATOR_HPP__

#include <string>
#include <ostream>
#include "sp_model.hpp"
#include "kmc_core.hpp"
#include "kmc_surface.hpp"
#include "param.hpp"

class Mediator{
public:
    Mediator(void);
    void setParam(Param *param);
    void setState(State *state);
    void setSPModel(SPModel *sp);
    void setKMC(KMCCore *kmc);
    void setSurface(KMCSurface *surface);
    void setStream(std::ostream &stream);
    void run(void);
private:
    Param *param;
    State *state;
    KMCCore *kmc;
    SPModel *sp;
    KMCSurface *surface;
    std::ostream *stream;
    int currentCycles;
    int lastDischargeTime;
    void init(void);
    void preCharge(void);
    void preDisCharge(void);
    void charge(void);
    void discharge(void);
    void outputLog(std::string label);
    void outputSurface(std::string label);
};

#endif
