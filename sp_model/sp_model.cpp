/*
  \file    sp_model.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "constant.hpp"
#include "sp_model.hpp"


SPModel::SPModel(double dt){
    this->dt = dt;
    this->time = 0;
    this->stepNum = 0;
    this->p = NULL;
    this->s = NULL;
}

void SPModel::setState(State *s){
    this->s = s;
    init();
}
void SPModel::setParam(Param *p){
    this->p = p;
    init();
}

void SPModel::step(void){
    calcAnodeAverageLithiumConcentration();
    calcCathodeAverageLithiumConcentration();
    calcAnodeSurfaceLithiumConcentration();
    calcCathodeSurfaceLithiumConcentration();
    calcAnodeDimensionlessLithiumConcentration();
    calcCathodeDimensionlessLithiumConcentration();
    calcCathodeLocalEquilibriumPotential();
    calcAnodeLocalEquilibriumPotential();
    calcAnodeOverPotential();
    calcCathodeOverPotential();
    calcAnodeLocalPotential();
    calcCathodeLocalPotential();
    calcCellVoltage();
}

int SPModel::getStepNum(void){ return stepNum; }
double SPModel::getTime(void){ return time; }


void SPModel::init(void){
    if( p==NULL || s==NULL ) return;
    s->setAnodeAverageLithiumConcentration( p->getAnodeInitialLithiumConcentration() );
    s->setCathodeAverageLithiumConcentration( p->getCathodeInitialLithiumConcentration() );
    calcAnodeSurfaceLithiumConcentration();
    calcCathodeSurfaceLithiumConcentration();
    calcAnodeDimensionlessLithiumConcentration();
    calcCathodeDimensionlessLithiumConcentration();
    calcCathodeLocalEquilibriumPotential();
    calcAnodeLocalEquilibriumPotential();
    calcAnodeOverPotential();
    calcCathodeOverPotential();
    calcAnodeLocalPotential();
    calcCathodeLocalPotential();
    calcCellVoltage();
}

void SPModel::calcAnodeAverageLithiumConcentration(void){
    double delta;
    delta = - ( 15 * p->getAnodeDiffusionCoefficient() / pow( p->getAnodeParticleRadius(), 2 )
                * ( s->getAnodeAverageLithiumConcentration() - s->getAnodeSurfaceLithiumConcentration() ) );
    s->setAnodeAverageLithiumConcentration( s->getAnodeAverageLithiumConcentration() + (delta * dt) );
}
void SPModel::calcCathodeAverageLithiumConcentration(void){
    double delta;
    delta = - ( 15 * p->getCathodeDiffusionCoefficient() / pow( p->getCathodeParticleRadius(), 2 )
                * ( s->getCathodeAverageLithiumConcentration() - s->getCathodeSurfaceLithiumConcentration() ) );
    s->setCathodeAverageLithiumConcentration( s->getCathodeAverageLithiumConcentration() + (delta * dt) );
}

void SPModel::calcAnodeSurfaceLithiumConcentration(void){
    double val;
    val = s->getAnodeAverageLithiumConcentration()
        - ( ( p->getAppliedCurrent() + s->getAnodeSideReactionCurrent() ) / ( p->getAnodeSurfaceArea() * constant::F )
            * p->getAnodeParticleRadius() / (5 * p->getAnodeDiffusionCoefficient() ) );
    s->setAnodeSurfaceLithiumConcentration( val );
}
void SPModel::calcCathodeSurfaceLithiumConcentration(void){
    double val;
    val = s->getCathodeAverageLithiumConcentration()
        - ( - p->getAppliedCurrent() / ( p->getCathodeSurfaceArea() * constant::F )
           * p->getCathodeParticleRadius() / (5 * p->getCathodeDiffusionCoefficient() ) );
    s->setCathodeSurfaceLithiumConcentration( val );
}

void SPModel::calcAnodeDimensionlessLithiumConcentration(void){
    double val;
    val = s->getAnodeAverageLithiumConcentration() / p->getAnodeMaxLithiumConcentration();
    s->setAnodeDimensionlessLithiumConcentration( val );
}
void SPModel::calcCathodeDimensionlessLithiumConcentration(void){
    double val;
    val = s->getCathodeAverageLithiumConcentration() / p->getCathodeMaxLithiumConcentration();
    s->setCathodeDimensionlessLithiumConcentration( val );
}

void SPModel::calcAnodeLocalEquilibriumPotential(void){
    double val;
    double theta = s->getAnodeDimensionlessLithiumConcentration();
    if(theta != 0.0){
        val = 0.72222 + 0.1387*theta + 0.029*sqrt(theta) - 0.0172/theta + 0.0019/pow(theta,1.5)
            + 0.2808*exp(0.9-15*theta) - 0.7984*exp(0.4465*theta-0.4108);
    }else{
        val = DBL_MAX; // theta->0 Un->+inf
    }
    s->setAnodeLocalEquilibriumPotential( val );
}
void SPModel::calcCathodeLocalEquilibriumPotential(void){
    double val;
    double theta = s->getCathodeDimensionlessLithiumConcentration();
    val = ( - 4.656 + 88.669*pow(theta,2) - 401.119*pow(theta,4) + 342.909*pow(theta,6) - 462.471*pow(theta,8) + 433.434*pow(theta,10) )
        / ( - 1.0 + 18.933*pow(theta,2) - 79.532*pow(theta,4) + 37.311*pow(theta,6) - 73.083*pow(theta,8) + 95.96*pow(theta,10) );
    s->setCathodeLocalEquilibriumPotential( val );
}

void SPModel::calcAnodeOverPotential(void){
    double val;
    val = ( asinh( (- p->getAppliedCurrent() + s->getAnodeSideReactionCurrent() )
                   / ( 2 * p->getAnodeSurfaceArea() * p->getAnodeReactionRateConstant() * constant::F
                       * sqrt( (p->getAnodeMaxLithiumConcentration() - s->getAnodeSurfaceLithiumConcentration() )
                               * s->getAnodeSurfaceLithiumConcentration() * p->getLiquidPhaseLithiumConcentration() ) ) )
            * constant::R * p->getTemperature() / ( p->getTransferCoefficients() * constant::F ) ) ;
    s->setAnodeOverPotential( val );
}
void SPModel::calcCathodeOverPotential(void){
    double val;
    val = ( asinh( - p->getAppliedCurrent()
                    / ( 2 * p->getCathodeSurfaceArea() * p->getCathodeReactionRateConstant() * constant::F
                       * sqrt( (p->getCathodeMaxLithiumConcentration() - s->getCathodeSurfaceLithiumConcentration() )
                               * s->getCathodeSurfaceLithiumConcentration() * p->getLiquidPhaseLithiumConcentration() ) ) )
            * constant::R * p->getTemperature() / ( p->getTransferCoefficients() * constant::F ) ) ;
    s->setCathodeOverPotential( val );
}

void SPModel::calcAnodeLocalPotential(void){
    double val;
    val = p->getLiquidPhaseLocalPotential() + s->getAnodeOverPotential() + s->getAnodeLocalEquilibriumPotential()
        + ( p->getAppliedCurrent() * s->getAnodeSideReactionCurrent() * s->getSEIThickness()
            / ( p->getAnodeSurfaceArea() * p->getElectrolyteConductivity() ) );
    s->setAnodeLocalPotential( val );
}
void SPModel::calcCathodeLocalPotential(void){
    double val;
    val = p->getLiquidPhaseLocalPotential() + s->getCathodeOverPotential() + s->getCathodeLocalEquilibriumPotential();
    s->setCathodeLocalPotential( val );
}

void SPModel::calcCellVoltage(void){
    double val;
    val = s->getCathodeLocalPotential() - s->getAnodeLocalPotential();
    s->setCellVoltage( val );
}
