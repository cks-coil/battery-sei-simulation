/*
  \file    param.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/ 

#ifndef __INCLUDED_PARAM_HPP__
#define __INCLUDED_PARAM_HPP__


class Param{
public:
    Param(void);
    void setTemperature(double temperature);
    void setUnitSEIThickness(double unitSEIThickness);
    void setUnitSEIArea(double unitSEIArea);
    void setElectrolyteConductivity(double electrolyteConductivity);
    void setTransferCoefficients(double transferCoefficients);
    void setAnodeSpecificArea(double anodeSpecificArea);
    void setAnodeSideReactionExchangeCurrentDensity(double anodeSideReactionExchangeCurrentDensity);
    double getTemperature(void);
    double getUnitSEIThickness(void);
    double getUnitSEIArea(void);
    double getElectrolyteConductivity(void);
    double getTransferCoefficients(void);
    double getAnodeSpecificArea(void);
    double getAnodeSideReactionExchangeCurrentDensity(void);
private:
    double temperature; // T [K]
    double unitSEIThickness; // [m / (particle)]
    double unitSEIArea;      // [m^2 / (particle)]
    double electrolyteConductivity; // κ [S m^-1]
    double transferCoefficients; // α [-]
    double anodeSpecificArea; // a_n [m^2 m^-3]
    double anodeSideReactionExchangeCurrentDensity; // i_{nj,side}^0 [A m^-2]
};

#endif



