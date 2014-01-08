/*
  \file    state.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
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
    cathodeSideReactionCurrent = 0;
    cathodeLocalPotential = 0;
    cathodeLocalEquilibriumPotential = 0;
    cathodeOverPotential = 0;
    cathodeAverageLithiumConcentration = 0;
    cathodeSurfaceLithiumConcentration = 0;
    cathodeDimensionlessLithiumConcentration = 0;
    SEIThickness = 0;
}

void State::setAnodeSideReactionCurrent(double anodeSideReactionCurrent){ this->anodeSideReactionCurrent = anodeSideReactionCurrent; }
void State::setAnodeLocalPotential(double anodeLocalPotential){ this->anodeLocalPotential = anodeLocalPotential; }
void State::setAnodeLocalEquilibriumPotential(double anodeLocalEquilibriumPotential){ this->anodeLocalEquilibriumPotential = anodeLocalEquilibriumPotential; }
void State::setAnodeOverPotential(double anodeOverPotential){ this->anodeOverPotential = anodeOverPotential; }
void State::setAnodeAverageLithiumConcentration(double anodeAverageLithiumConcentration){ this->anodeAverageLithiumConcentration = anodeAverageLithiumConcentration; }
void State::setAnodeSurfaceLithiumConcentration(double anodeSurfaceLithiumConcentration){ this->anodeSurfaceLithiumConcentration = anodeSurfaceLithiumConcentration; }
void State::setAnodeDimensionlessLithiumConcentration(double anodeDimensionlessLithiumConcentration){ this->anodeDimensionlessLithiumConcentration = anodeDimensionlessLithiumConcentration; }
void State::setCathodeSideReactionCurrent(double cathodeSideReactionCurrent){ this->cathodeSideReactionCurrent = cathodeSideReactionCurrent; }
void State::setCathodeLocalPotential(double cathodeLocalPotential){ this->cathodeLocalPotential = cathodeLocalPotential; }
void State::setCathodeLocalEquilibriumPotential(double cathodeLocalEquilibriumPotential){ this->cathodeLocalEquilibriumPotential = cathodeLocalEquilibriumPotential; }
void State::setCathodeOverPotential(double cathodeOverPotential){ this->cathodeOverPotential = cathodeOverPotential; }
void State::setCathodeAverageLithiumConcentration(double cathodeAverageLithiumConcentration){ this->cathodeAverageLithiumConcentration = cathodeAverageLithiumConcentration; }
void State::setCathodeSurfaceLithiumConcentration(double cathodeSurfaceLithiumConcentration){ this->cathodeSurfaceLithiumConcentration = cathodeSurfaceLithiumConcentration; }
void State::setCathodeDimensionlessLithiumConcentration(double cathodeDimensionlessLithiumConcentration){ this->cathodeDimensionlessLithiumConcentration = cathodeDimensionlessLithiumConcentration; }
void State::setSEIThickness(double SEIThickness){ this->SEIThickness = SEIThickness; }

double State::getAnodeSideReactionCurrent(void){ return this->anodeSideReactionCurrent; }
double State::getAnodeLocalPotential(void){ return this->anodeLocalPotential; }
double State::getAnodeLocalEquilibriumPotential(void){ return this->anodeLocalEquilibriumPotential; }
double State::getAnodeOverPotential(void){ return this->anodeOverPotential; }
double State::getAnodeAverageLithiumConcentration(void){ return this->anodeAverageLithiumConcentration; }
double State::getAnodeSurfaceLithiumConcentration(void){ return this->anodeSurfaceLithiumConcentration; }
double State::getAnodeDimensionlessLithiumConcentration(void){ return this->anodeDimensionlessLithiumConcentration; }
double State::getCathodeSideReactionCurrent(void){ return this->cathodeSideReactionCurrent; }
double State::getCathodeLocalPotential(void){ return this->cathodeLocalPotential; }
double State::getCathodeLocalEquilibriumPotential(void){ return this->cathodeLocalEquilibriumPotential; }
double State::getCathodeOverPotential(void){ return this->cathodeOverPotential; }
double State::getCathodeAverageLithiumConcentration(void){ return this->cathodeAverageLithiumConcentration; }
double State::getCathodeSurfaceLithiumConcentration(void){ return this->cathodeSurfaceLithiumConcentration; }
double State::getCathodeDimensionlessLithiumConcentration(void){ return this->cathodeDimensionlessLithiumConcentration; }
double State::getSEIThickness(void){ return this->SEIThickness; }

