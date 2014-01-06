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
    void setUnitSEIArea(double unitSEIArea);
    void setElectrolyteConductivity(double electrolyteConductivity);
    void setTransferCoefficients(double transferCoefficients);
    void setAnodeLocalEquilibriumPotential(double anodeLocalEquilibriumPotential);
    double getUnitSEIThickness(void);
    double getUnitSEIArea(void);
    double getElectrolyteConductivity(void);
    double getTransferCoefficients(void);
    double getAnodeLocalEquilibriumPotential(void);
private:
    double unitSEIThickness; // [m / (particle)]
    double unitSEIArea;      // [m^2 / (particle)]
    double electrolyteConductivity; // κ [S m^-1]
    double transferCoefficients; // α [-]
    double anodeLocalEquilibriumPotential; // Un [V]

};

#endif

