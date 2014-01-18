/*
  \file    parser.hpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
*/

#ifndef __INCLUDED_PARSER_HPP__
#define __INCLUDED_PARSER_HPP__

#include <string>
#include <map>
#include "param.hpp"


class Parser{
public:
    Parser(void);
    void setFileName(std::string fileName);
    void setParam(Param *param);
    void parse(void);
private:
    Param *param;
    std::string fileName;
    std::map<std::string, void(Param::*)(double)> doubleFuncMap;
    std::map<std::string, void(Param::*)(int)> intFuncMap;
    bool doubleParser(std::string label, std::string val);
    bool intParser(std::string label, std::string val);
    void initDoubleFuncMap(void);
    void initIntFuncMap(void);
};

#endif
