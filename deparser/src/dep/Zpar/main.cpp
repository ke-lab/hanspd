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
    zp.load();
    std::vector<std::pair<std::string,std::string>> s;
    s.push_back(make_pair(std::string("上海"),std::string("NR")));
    s.push_back(make_pair(std::string("浦东"),std::string("NR")));
    s.push_back(make_pair(std::string("开发"),std::string("NN")));
    s.push_back(make_pair(std::string("与"),std::string("CC")));
    s.push_back(make_pair(std::string("法制"),std::string("NN")));
    s.push_back(make_pair(std::string("建设"),std::string("NN")));
    s.push_back(make_pair(std::string("同步"),std::string("VV")));
    std::vector<Dependency_TreeNode> aaa=zp.depparser(s);
    std::cout<<std::endl;
    for(int i=0;i<aaa.size();i++)
        std::cout<<aaa[i].word<<"\t"<<aaa[i].tag<<"\t"<<aaa[i].label<<"\t"<<aaa[i].head<<std::endl;
    return 0;
}