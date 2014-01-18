/*
  \file   main.cpp
  \author Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>
 */

#include <iostream>
#include <fstream>
#include <time.h>
#include <boost/program_options.hpp>
#include <string>
#include <vector>
#include "state.hpp"
#include "param.hpp"
#include "parser.hpp"
#include "kmc_core.hpp"
#include "kmc_surface.hpp"
#include "kmc_transition.hpp"
#include "kmc_adsorption.hpp"
#include "sp_model.hpp"
#include "mediator.hpp"

using namespace std;
using namespace boost::program_options;


int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));

    options_description opt("Option");
    opt.add_options()
        ("help,h", "show help")
        ("param,p", value<string>(),"param file")
        ("output,o", value<string>(), "output file");

    variables_map argmap;
    store(parse_command_line(argc, argv, opt), argmap);
    notify(argmap);

    if( argmap.count("help") ){
        cerr << opt << endl;
        exit(1);
    } 

    string outputFileName;
    if( !argmap.count("output") ) outputFileName = "tmp.log";
    else outputFileName = argmap["output"].as<string>();

    ofstream ofs(outputFileName.c_str());
    if( !ofs ){
        cerr << "# ERROR: can't open file for output: " << outputFileName << endl;
        exit(1);
    }

    State state;
    Param param;
    Parser parser;
    parser.setParam(&param);
    parser.setFileName("default.txt");
    parser.parse();
    if( argmap.count("param") ){
        parser.setFileName(argmap["param"].as<string>());
        parser.parse();
    }
    ofs << param << endl;

    SPModel sp;
    sp.setState(&state);
    sp.setParam(&param);

    KMCCore kmc;
    KMCSurface surface;
    KMCAdsorption adsorption;
    kmc.setParam(&param);
    kmc.setState(&state);
    kmc.setSurface(&surface);
    kmc.setTransition(&adsorption);

    Mediator mediator;
    mediator.setParam(&param);
    mediator.setState(&state);
    mediator.setKMC(&kmc);
    mediator.setSPModel(&sp);
    mediator.setStream(ofs);
    mediator.run();

    ofs.close();

    return 0;
}
