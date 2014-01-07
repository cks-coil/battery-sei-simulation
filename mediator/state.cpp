/*
  \file    state.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "state.hpp"

State::State(void){
    solidPhaseLocalPotential = 0.0;
    liquidPhaseLocalPotential = 0.0;
    anodeIntercalationCurrentDensity = 0.0;
    anodeSideReactionCurrentDensity = 0.0;
}

void State::setSolidPhaseLocalPotential(double solidPhaseLocalPotential){ this->solidPhaseLocalPotential = solidPhaseLocalPotential; }
void State::setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential){ this->liquidPhaseLocalPotential = liquidPhaseLocalPotential; }
void State::setAnodeIntercalationCurrentDensity(double anodeIntercalationCurrentDensity){ this->anodeIntercalationCurrentDensity = anodeIntercalationCurrentDensity; }
void State::setAnodeSideReactionCurrentDensity(double anodeSideReactionCurrentDensity){ this->anodeSideReactionCurrentDensity = anodeIntercalationCurrentDensity; }

double State::getSolidPhaseLocalPotential(void){ return this->solidPhaseLocalPotential; }
double State::getLiquidPhaseLocalPotential(void){ return this->liquidPhaseLocalPotential; }
double State::getAnodeIntercalationCurrentDensity(void){ return this->anodeIntercalationCurrentDensity; }
double State::getAnodeSideReactionCurrentDensity(void){ return this->anodeSideReactionCurrentDensity; }
