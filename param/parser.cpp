/*
  \file    parser.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <errno.h>
#include <math.h>
#include "parser.hpp"

using namespace::std;

Parser::Parser(void){
    this->fileName = "";
    this->param = NULL;
    initDoubleFuncMap();
    initIntFuncMap();
}

void Parser::setFileName(string fileName){ this->fileName = fileName; }
void Parser::setParam(Param *param){ this->param = param; }

void Parser::parse(void){
    ifstream ifs(fileName.c_str());
    string buf;
    vector <string> v;
    bool flag;

    if( ifs == NULL ){
        cerr << "# ERROR: can't open file '" << fileName << "'" << endl;
        exit(1);
    }

    while( getline(ifs, buf) ){
        boost::algorithm::trim(buf); // 前後の空白削除
        boost::algorithm::split(v, buf, boost::algorithm::is_space(), boost::algorithm::token_compress_on);

        if( (int)v.size() == 0 ) continue;
        if( v[0].find("#") != string::npos ) continue; // #から始まる行は無視

        if( (int)v.size() == 1 ){
            cerr << "# ParseERROR: value is empty :" << buf << endl;
            exit(1);
        }
        if( (int)v.size() !=2 ){
            if( v[2].find("#") == string::npos ){
                cerr << "# ParseERROR: too many string :" << buf << endl;
                exit(1);
            }
        }

        flag = doubleParser(v[0], v[1]);
        if(!flag) flag = intParser(v[0], v[1]);
        if(!flag){
            cerr << "# ParseERROR: no such label: " << buf << endl;
            exit(1);
        } 
    }
}

bool Parser::doubleParser(string label, string val){
    double value;
    char *endptr = NULL;
    if( !doubleFuncMap.count(label) ) return false;

    errno = 0;
    value = strtod(val.c_str(), &endptr);
    if( (errno !=0) || (*endptr != '\0') ){ // 変換失敗
        cerr << "# ParseERROR: can't change \"" << val << "\" to \"double\", label: \"" << label << "\"" << endl;
        exit(1);
    }
    (param->*(doubleFuncMap.find(label)->second))(value);
    return true;
}

bool Parser::intParser(string label, string val){
    long value;
    char *endptr = NULL;
    if( !intFuncMap.count(label) ) return false;

    errno = 0;
    value = strtol(val.c_str(), &endptr, 0);
    if( (errno != 0) || (*endptr != '\0') || (value > INT_MAX) || (value < INT_MIN) ){ // 変換失敗
        cerr << "# ParseERROR: can't change \"" << val << "\" to \"int\", label: \"" << label << "\"" << endl;
        exit(1);
    }

    (param->*(intFuncMap.find(label)->second))((int)value);
    return true;
}


void Parser::initDoubleFuncMap(void){
    doubleFuncMap.insert(make_pair("anodeSurfaceArea", &Param::setAnodeSurfaceArea));
    doubleFuncMap.insert(make_pair("anodeReactionRateConstant", &Param::setAnodeReactionRateConstant));
    doubleFuncMap.insert(make_pair("anodeMaxLithiumConcentration", &Param::setAnodeMaxLithiumConcentration));
    doubleFuncMap.insert(make_pair("anodeInitialLithiumConcentration", &Param::setAnodeInitialLithiumConcentration));
    doubleFuncMap.insert(make_pair("anodeParticleRadius", &Param::setAnodeParticleRadius));
    doubleFuncMap.insert(make_pair("anodeDiffusionCoefficient", &Param::setAnodeDiffusionCoefficient));
    doubleFuncMap.insert(make_pair("anodeSideReactionExchangeCurrentDensity", &Param::setAnodeSideReactionExchangeCurrentDensity));
    doubleFuncMap.insert(make_pair("cathodeSurfaceArea", &Param::setCathodeSurfaceArea));
    doubleFuncMap.insert(make_pair("cathodeReactionRateConstant", &Param::setCathodeReactionRateConstant));
    doubleFuncMap.insert(make_pair("cathodeMaxLithiumConcentration", &Param::setCathodeMaxLithiumConcentration));
    doubleFuncMap.insert(make_pair("cathodeInitialLithiumConcentration", &Param::setCathodeInitialLithiumConcentration));
    doubleFuncMap.insert(make_pair("cathodeParticleRadius", &Param::setCathodeParticleRadius));
    doubleFuncMap.insert(make_pair("cathodeDiffusionCoefficient", &Param::setCathodeDiffusionCoefficient));
    doubleFuncMap.insert(make_pair("liquidPhaseLithiumConcentration", &Param::setLiquidPhaseLithiumConcentration));
    doubleFuncMap.insert(make_pair("liquidPhaseLocalPotential", &Param::setLiquidPhaseLocalPotential));
    doubleFuncMap.insert(make_pair("transferCoefficients", &Param::setTransferCoefficients));
    doubleFuncMap.insert(make_pair("temperature", &Param::setTemperature));
    doubleFuncMap.insert(make_pair("appliedCurrent", &Param::setAppliedCurrent));
    doubleFuncMap.insert(make_pair("SEILocalEquilibriumPotential", &Param::setSEILocalEquilibriumPotential));
    doubleFuncMap.insert(make_pair("SEIElectronicConductivity", &Param::setSEIElectronicConductivity));
    doubleFuncMap.insert(make_pair("SEIUnitArea", &Param::setSEIUnitArea));
    doubleFuncMap.insert(make_pair("SEIUnitThickness", &Param::setSEIUnitThickness));
    doubleFuncMap.insert(make_pair("upperCutoffVoltage", &Param::setUpperCutoffVoltage));
    doubleFuncMap.insert(make_pair("lowerCutoffVoltage", &Param::setLowerCutoffVoltage));
    doubleFuncMap.insert(make_pair("adsorptionOneSideCoeff", &Param::setAdsorptionOneSideCoeff));
    doubleFuncMap.insert(make_pair("adsorptionTwoSideCoeff", &Param::setAdsorptionTwoSideCoeff));
    doubleFuncMap.insert(make_pair("adsorptionThreeSideCoeff", &Param::setAdsorptionThreeSideCoeff));
    doubleFuncMap.insert(make_pair("adsorptionFourSideCoeff", &Param::setAdsorptionFourSideCoeff));
    doubleFuncMap.insert(make_pair("SPModelDeltaTime", &Param::setSPModelDeltaTime));
}

void Parser::initIntFuncMap(void){
    intFuncMap.insert(make_pair("KMCSurfaceSizeX", &Param::setKMCSurfaceSizeX));
    intFuncMap.insert(make_pair("KMCSurfaceSizeY", &Param::setKMCSurfaceSizeY));
    intFuncMap.insert(make_pair("MediatorEndCycles", &Param::setMediatorEndCycles));
}

