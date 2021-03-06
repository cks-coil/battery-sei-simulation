/*
  \File    State.Cpp
  \Author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "state.hpp"

State::State(void){
    appliedCurrent = 0;
    anodeSideReactionCurrent = 0;
    anodeLocalPotential = 0;
    anodeLocalEquilibriumPotential = 0;
    anodeOverPotential = 0;
    anodeAverageLithiumConcentration = 0;
    anodeSurfaceLithiumConcentration = 0;
    anodeDimensionlessLithiumConcentration = 0;
    cathodeLocalPotential = 0;
    cathodeLocalEquilibriumPotential = 0;
    cathodeOverPotential = 0;
    cathodeAverageLithiumConcentration = 0;
    cathodeSurfaceLithiumConcentration = 0;
    cathodeDimensionlessLithiumConcentration = 0;
    cellVoltage = 0;
    capacity = 0;
    SEIThickness = 0;
    lithiumLoss = 0;
    dimensionlessLithiumLoss = 0;
}

void State::outputMultiLine(std::ostream &out){
    out << "# capacity" << capacity << std::endl
        << "# cellVoltage" << cellVoltage << std::endl
        << "# appliedCurrent: " << appliedCurrent << std::endl
        << "# anodeSideReactionCurrent: " << anodeSideReactionCurrent << std::endl
        << "# anodeLocalPotential: " << anodeLocalPotential << std::endl
        << "# anodeLocalEquilibriumPotential: " << anodeLocalEquilibriumPotential << std::endl
        << "# anodeOverPotential: " << anodeOverPotential << std::endl
        << "# anodeAverageLithiumConcentration: " << anodeAverageLithiumConcentration << std::endl
        << "# anodeSurfaceLithiumConcentration: " << anodeSurfaceLithiumConcentration << std::endl
        << "# anodeDimensionlessLithiumConcentration: " << anodeDimensionlessLithiumConcentration << std::endl
        << "# cathodeLocalPotential: " << cathodeLocalPotential << std::endl
        << "# cathodeLocalEquilibriumPotential: " << cathodeLocalEquilibriumPotential << std::endl
        << "# cathodeOverPotential: " << cathodeOverPotential << std::endl
        << "# cathodeAverageLithiumConcentration: " << cathodeAverageLithiumConcentration << std::endl
        << "# cathodeSurfaceLithiumConcentration: " << cathodeSurfaceLithiumConcentration << std::endl
        << "# cathodeDimensionlessLithiumConcentration: " << cathodeDimensionlessLithiumConcentration << std::endl
        << "# SEIthickness: " << SEIThickness << std::endl
        << "# lithiumLoss: " << lithiumLoss << std::endl
        << "# dimensionlessLithiumLoss: " << dimensionlessLithiumLoss << std::endl;
}
void State::outputSingleLine(std::ostream &out){
    out  << capacity << " "
         << cellVoltage << " "
         << appliedCurrent << " "
         << anodeSideReactionCurrent << " "
         << anodeLocalPotential << " "
         << anodeLocalEquilibriumPotential << " "
         << anodeOverPotential << " "
         << anodeAverageLithiumConcentration << " "
         << anodeSurfaceLithiumConcentration << " "
         << anodeDimensionlessLithiumConcentration << " "
         << cathodeLocalPotential << " "
         << cathodeLocalEquilibriumPotential << " "
         << cathodeOverPotential << " "
         << cathodeAverageLithiumConcentration << " "
         << cathodeSurfaceLithiumConcentration << " "
         << cathodeDimensionlessLithiumConcentration << " "
         << SEIThickness << " "
         << lithiumLoss << " "
         << dimensionlessLithiumLoss;
}

void State::setAppliedCurrent(double appliedCurrent){ this->appliedCurrent = appliedCurrent; }
void State::setAnodeSideReactionCurrent(double anodeSideReactionCurrent){ this->anodeSideReactionCurrent = anodeSideReactionCurrent; }
void State::setAnodeLocalPotential(double anodeLocalPotential){ this->anodeLocalPotential = anodeLocalPotential; }
void State::setAnodeLocalEquilibriumPotential(double anodeLocalEquilibriumPotential){ this->anodeLocalEquilibriumPotential = anodeLocalEquilibriumPotential; }
void State::setAnodeOverPotential(double anodeOverPotential){ this->anodeOverPotential = anodeOverPotential; }
void State::setAnodeAverageLithiumConcentration(double anodeAverageLithiumConcentration){ this->anodeAverageLithiumConcentration = anodeAverageLithiumConcentration; }
void State::setAnodeSurfaceLithiumConcentration(double anodeSurfaceLithiumConcentration){ this->anodeSurfaceLithiumConcentration = anodeSurfaceLithiumConcentration; }
void State::setAnodeDimensionlessLithiumConcentration(double anodeDimensionlessLithiumConcentration){ this->anodeDimensionlessLithiumConcentration = anodeDimensionlessLithiumConcentration; }
void State::setCathodeLocalPotential(double cathodeLocalPotential){ this->cathodeLocalPotential = cathodeLocalPotential; }
void State::setCathodeLocalEquilibriumPotential(double cathodeLocalEquilibriumPotential){ this->cathodeLocalEquilibriumPotential = cathodeLocalEquilibriumPotential; }
void State::setCathodeOverPotential(double cathodeOverPotential){ this->cathodeOverPotential = cathodeOverPotential; }
void State::setCathodeAverageLithiumConcentration(double cathodeAverageLithiumConcentration){ this->cathodeAverageLithiumConcentration = cathodeAverageLithiumConcentration; }
void State::setCathodeSurfaceLithiumConcentration(double cathodeSurfaceLithiumConcentration){ this->cathodeSurfaceLithiumConcentration = cathodeSurfaceLithiumConcentration; }
void State::setCathodeDimensionlessLithiumConcentration(double cathodeDimensionlessLithiumConcentration){ this->cathodeDimensionlessLithiumConcentration = cathodeDimensionlessLithiumConcentration; }
void State::setCellVoltage(double cellVoltage){ this->cellVoltage = cellVoltage; }
void State::setCapacity(double capacity){ this->capacity = capacity; }
void State::setSEIThickness(double SEIThickness){ this->SEIThickness = SEIThickness; }
void State::setLithiumLoss(double lithiumLoss){ this->lithiumLoss = lithiumLoss; }
void State::setDimensionlessLithiumLoss(double dimensionlessLithiumLoss){ this->dimensionlessLithiumLoss = dimensionlessLithiumLoss; }

double State::getAppliedCurrent(void){ return this->appliedCurrent; }
double State::getAnodeSideReactionCurrent(void){ return this->anodeSideReactionCurrent; }
double State::getAnodeLocalPotential(void){ return this->anodeLocalPotential; }
double State::getAnodeLocalEquilibriumPotential(void){ return this->anodeLocalEquilibriumPotential; }
double State::getAnodeOverPotential(void){ return this->anodeOverPotential; }
double State::getAnodeAverageLithiumConcentration(void){ return this->anodeAverageLithiumConcentration; }
double State::getAnodeSurfaceLithiumConcentration(void){ return this->anodeSurfaceLithiumConcentration; }
double State::getAnodeDimensionlessLithiumConcentration(void){ return this->anodeDimensionlessLithiumConcentration; }
double State::getCathodeLocalPotential(void){ return this->cathodeLocalPotential; }
double State::getCathodeLocalEquilibriumPotential(void){ return this->cathodeLocalEquilibriumPotential; }
double State::getCathodeOverPotential(void){ return this->cathodeOverPotential; }
double State::getCathodeAverageLithiumConcentration(void){ return this->cathodeAverageLithiumConcentration; }
double State::getCathodeSurfaceLithiumConcentration(void){ return this->cathodeSurfaceLithiumConcentration; }
double State::getCathodeDimensionlessLithiumConcentration(void){ return this->cathodeDimensionlessLithiumConcentration; }
double State::getCellVoltage(void){ return this->cellVoltage; }
double State::getCapacity(void){ return this->capacity; }
double State::getSEIThickness(void){ return this->SEIThickness; }
double State::getLithiumLoss(void){ return this->lithiumLoss; }
double State::getDimensionlessLithiumLoss(void){ return this->dimensionlessLithiumLoss; }

void State::operator=(State &source){
    if(this == &source) return;
    this->appliedCurrent = source.getAppliedCurrent();
    this->anodeSideReactionCurrent = source.getAnodeSideReactionCurrent();
    this->anodeLocalPotential = source.getAnodeLocalPotential();
    this->anodeLocalEquilibriumPotential = source.getAnodeLocalEquilibriumPotential();
    this->anodeOverPotential = source.getAnodeOverPotential();
    this->anodeAverageLithiumConcentration = source.getAnodeAverageLithiumConcentration();
    this->anodeSurfaceLithiumConcentration = source.getAnodeSurfaceLithiumConcentration();
    this->anodeDimensionlessLithiumConcentration = source.getAnodeDimensionlessLithiumConcentration();
    this->cathodeLocalPotential = source.getCathodeLocalPotential();
    this->cathodeLocalEquilibriumPotential = source.getCathodeLocalEquilibriumPotential();
    this->cathodeOverPotential = source.getCathodeOverPotential();
    this->cathodeAverageLithiumConcentration = source.getCathodeAverageLithiumConcentration();
    this->cathodeSurfaceLithiumConcentration = source.getCathodeSurfaceLithiumConcentration();
    this->cathodeDimensionlessLithiumConcentration = source.getCathodeDimensionlessLithiumConcentration();
    this->cellVoltage = source.getCellVoltage();
    this->capacity = source.getCapacity();
    this->SEIThickness = source.getSEIThickness();
    this->lithiumLoss = source.getLithiumLoss();
    this->dimensionlessLithiumLoss = source.getDimensionlessLithiumLoss();
}

std::ostream &operator<<(std::ostream &out, State &tgt){
    tgt.outputSingleLine(out);
    return out;
}
