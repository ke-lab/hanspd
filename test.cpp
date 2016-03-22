//
// Created by 王鹏飞 on 16/3/20.
//

#include <iostream>
#include <tagger/crf/CRFTagger.h>
#include "Zpar.h"
#include <rapidjson/document.h>
#include <iostream>
#include <fstream>


#define ELPP_DEFAULT_LOG_FILE "logs/hanspd-test-%datetime.log"

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#include "base_seger.h"
int main(int argc,char**argv){
    using namespace std;

    Base_Tagger *tagger = Base_Tagger::load("/Users/wangpf/Desktop/model1","CRF");
    vector<u32string>sentence{U"扬帆",U"远东",U"做",U"与",U"中国",U"合作",U"的",U"先行"};
    auto res=tagger->predict(sentence);
    for(auto i=res.begin();i!=res.end();i++){
        cout<<i->first<<i->second<<endl;
    }

    std::string config_file=argv[1];
    std::ifstream in(config_file,std::ios::in);
    std::istreambuf_iterator<char> beg(in), end;
    std::string jsondata(beg, end);
    rapidjson::Document document;
    document.Parse(jsondata.c_str());
    Zpar zp(document);
    zp.load();
    std::vector<Dependency_TreeNode> aaa=zp.depparser(s);
    std::cout<<std::endl;
    for(int i=0;i<aaa.size();i++)
        std::cout<<aaa[i].word<<"\t"<<aaa[i].tag<<"\t"<<aaa[i].label<<"\t"<<aaa[i].head<<std::endl;



    cout << "Hello, hanspd!" << endl;
}
