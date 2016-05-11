#include "Zpar.h"
#include <fstream>
#include <stdlib.h>
#include <string>

Zpar::Zpar(){}

Zpar::~Zpar(){
    (*Par).~CDepParser();
}


Zpar::Zpar(const rapidjson::Document &config){
    corpus_path = config["corpus_path"].GetString();
    num_iterations=config["num_iterations"].GetInt();
    modelfile=config["modelfile"].GetString();
}


void Zpar::train(const std::string &dest_model) {
    std::string str("/home/wpf/hanspd/deparser/lib/train");
    str+=" "+corpus_path+" "+dest_model+" "+std::to_string(num_iterations);
    std::cout<<str<<std::endl;
    system(str.c_str());
}


bool Zpar::load(){
    Par=new CDepParser(modelfile, false, false);
    return true;
}

std::vector<Dependency_TreeNode> Zpar::depparser(std::vector<std::pair<std::string,std::string>> const &sentence) const{
    std::vector<Dependency_TreeNode> ans;
    int nBest=1;
    CDependencyParse *output_sent=new CDependencyParse[nBest];
    depparser::SCORE_TYPE *scores=0;
    (*Par).parse(sentence , output_sent ,nBest,scores);
    for(int i=0;i<(*output_sent).size();i++){
        Dependency_TreeNode s;
        s.head=(*output_sent)[i].head;
        s.tag=(*output_sent)[i].tag;
        s.label=(*output_sent)[i].label;
        s.word=(*output_sent)[i].word;
        ans.push_back(s);
    }
    delete [] output_sent ;
    return ans;

}
