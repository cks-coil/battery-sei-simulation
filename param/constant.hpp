/*
  \file    constant.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_CONSTANT_HPP__
#define __INCLUDED_CONSTANT_HPP__

#include <math.h>

namespace constant{
    const double R = 8.314; // Universal gas constant [J/mol/K]
    const double F = 96487; // Faraday's constant [C/Mol]
    const double NA = 6.02 * pow(10,23); // Avogadro constant [mol^-1];
    const double kB = 8.6173324 * pow(10,-5); // Boltzman constant [eV K^-1];
}

#endif
