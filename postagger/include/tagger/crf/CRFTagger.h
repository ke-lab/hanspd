//
// Created by 王鹏飞 on 16/2/29.
//

#ifndef POSTAGGER_CRFTAGGER_H
#define POSTAGGER_CRFTAGGER_H

#include <string>
#include <vector>
#include <tagger/preprocessor/PreProcessor.h>
#include <tagger/Base_Tagger.h>
#include <rapidjson/document.h>
#include <tagger/crf/crfpp.h>
#include <utility>


    class CRFTagger: public Base_Tagger {
    public:
        CRFTagger(const std::string &model);
        CRFTagger(const rapidjson::Document &config);
        std::vector< std::pair<std::string,std::string> > predict(std::vector<std::u32string> const &sentence) const ;
        void train(const std::string &dest_model);
        bool save(std::string const &model_path) ;

    private:
        CRFPP::Tagger *tagger;
        std::string template_path;
        std::string corpus_path;
        static PreProcessor preProcessor;

    };

#endif //POSTAGGER_CRFTAGGER_H
