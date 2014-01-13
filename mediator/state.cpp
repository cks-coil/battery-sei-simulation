/*
  \File    State.Cpp
  \Author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include "state.hpp"

State::State(void){
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
    SEIThickness = 0;
}

void State::output(std::ostream &out){
    out << "# anodeSideReactionCurrent: " << anodeSideReactionCurrent << std::endl
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
        << "# cellVoltage" << cellVoltage << std::endl
        << "# SEIThickness: " << SEIThickness << std::endl;
}

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
void State::setSEIThickness(double SEIThickness){ this->SEIThickness = SEIThickness; }

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
double State::getSEIThickness(void){ return this->SEIThickness; }

void State::operator=(State &source){
    if(this == &source) return;
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
    this->SEIThickness = source.getSEIThickness();
}
