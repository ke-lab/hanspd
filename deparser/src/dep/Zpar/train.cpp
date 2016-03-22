//
// Created by bruce on 16-3-15.
//

#include "Zpar.h"
#include <rapidjson/document.h>
#include <iostream>
#include <fstream>

int main(int argc,char** argv){
    std::string config_file=argv[1];
    std::ifstream in(config_file,std::ios::in);
    std::istreambuf_iterator<char> beg(in), end;
    std::string jsondata(beg, end);
    rapidjson::Document document;
    document.Parse(jsondata.c_str());
    Zpar zp(document);
    zp.train("/home/bruce/ClionProjects/DepPar/model/model");
    return 0;
}