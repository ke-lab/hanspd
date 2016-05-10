//
// Created by 王鹏飞 on 16/3/20.
//

#include <iostream>
#include <tagger/crf/CRFTagger.h>
#include "Zpar.h"
#include <rapidjson/document.h>
#include <iostream>
#include <fstream>
#include <string>
#include <utf8_io.h>


#define ELPP_DEFAULT_LOG_FILE "logs/hanspd-test-%datetime.log"

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#include "base_seger.h"

int main(int argc,char**argv){

    std::string pos_model=argv[1];
    Base_Tagger *tagger = Base_Tagger::load(pos_model,"CRF");
    el::Logger* mainLogger = el::Loggers::getLogger("main");

    std::string const seger_model_path = "/home/public/emws_2016-03-28_10-46.model";
    mainLogger->info("load model ...");
    base_seger *seger = base_seger::load(seger_model_path, "emws");

    mainLogger->info("reading sentences from document ...");
    std::string const document_path = "/home/junfeng/hanspd/working_data/pku_test.raw";
    std::vector<std::u32string> sentences = utf8_io::readlines(document_path);

    mainLogger->info("predict ...");
    auto seged_sentences = seger->predict(sentences);

    auto output_path = document_path + ".seged";
    mainLogger->info("save segmented document ...");
    bool flag = utf8_io::writewords(output_path, seged_sentences, U' ', U'\n');
    if (!flag) {
        mainLogger->error("write words to %v error", output_path);
    }
    delete seger;

    Base_Tagger *tagger = Base_Tagger::load("/Users/wangpf/Desktop/model1","CRF");
    std::vector<std::u32string>sentence{U"扬帆",U"远东",U"做",U"与",U"中国",U"合作",U"的",U"先行"};
    auto res=tagger->predict(sentence);
    for(auto i=res.begin();i!=res.end();i++){
        std::cout<<i->first<<i->second<<std::endl;
    }

    std::string config_file=argv[2];
    std::ifstream in(config_file,std::ios::in);
    std::istreambuf_iterator<char> beg(in), end;
    std::string jsondata(beg, end);
    rapidjson::Document document;
    document.Parse(jsondata.c_str());
    Zpar zp(document);
    zp.load();

    std::vector<Dependency_TreeNode> aaa=zp.depparser(res);
    std::cout<<std::endl;
    for(int i=0;i<aaa.size();i++)
        std::cout<<aaa[i].word<<"\t"<<aaa[i].tag<<"\t"<<aaa[i].label<<"\t"<<aaa[i].head<<std::endl;
    return 0;



}
