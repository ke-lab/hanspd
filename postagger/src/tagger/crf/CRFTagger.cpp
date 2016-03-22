//
// Created by 王鹏飞 on 16/2/29.
//

#include <tagger/crf/CRFTagger.h>
#include <fstream>
#include <sstream>
#include <tagger/preprocessor/strtool.h>


PreProcessor CRFTagger::preProcessor{};

CRFTagger::CRFTagger(const std::string &model){
    std::string arg("-m ");
    arg.append(model);
    tagger = CRFPP::createTagger(arg.c_str());
}
CRFTagger::CRFTagger(const rapidjson::Document &config){
    template_path=config["template_path"].GetString();
    corpus_path = config["corpus_path"].GetString();
}


void CRFTagger::train(const std::string &dest_model) {
    std::string modefied_train=preProcessor.modify_file_for_train(corpus_path);
    preProcessor.train_model(template_path,modefied_train,dest_model);
    remove(modefied_train.c_str());
}

std::vector< std::pair<std::string,std::string> > CRFTagger::predict(std::vector<std::u32string> const &sentence)const {

    std::ostringstream  input_os;
    for(auto pos=sentence.begin();pos!=sentence.end();pos++){
        std::string u8_word=strtool::To_UTF8(*pos);
        input_os<<u8_word<<std::endl;

    }
    std::string res=tagger->parse(input_os.str().c_str());
    //转化输出结果
    std::vector<std::pair<std::string,std::string>>svec;
    res = strtool::trim(res);
    std::istringstream input_res(res);
    for (std::string line; std::getline(input_res, line); ) {
        std::vector<std::string>w_h;
        strtool::split(line,w_h,"\t");
        svec.push_back({w_h[0],w_h[1]});
    }
    return svec;
}

bool CRFTagger::save(std::string const &model_path){
    return true;
}


