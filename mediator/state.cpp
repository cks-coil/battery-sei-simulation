/*
  \file    state.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

void Param::setSolidPhaseLocalPotential(double solidPhaseLocalPotential){ this->solidPhaseLocalPotential = solidPhaseLocalPotential; }
void Param::setLiquidPhaseLocalPotential(double liquidPhaseLocalPotential){ this->liquidPhaseLocalPotential = liquidPhaseLocalPotential; }
void Param::setAnodeIntercalationCurrentDensity(double anodeIntercalationCurrentDensity){ this->anodeIntercalationCurrentDensity = anodeIntercalationCurrentDensity}
void Param::setAnodeSideReactionCurrentDensity(double anodeSideReactionCurrentDensity){ this->anodeSideReactionCurrentDensity = anodeIntercalationCurrentDensity; }

double Param::getSolidPhaseLocalPotential(void){ return this->solidPhaseLocalPotential; }
double Param::getLiquidPhaseLocalPotential(void){ return this->liquidPhaseLocalPotential; }
double Param::getAnodeIntercalationCurrentDensity(void){ return this->anodeIntercalationCurrentDensity; }
double Param::getAnodeSideReactionCurrentDensity(void){ return this->anodeSideReactionCurrentDensity; }
