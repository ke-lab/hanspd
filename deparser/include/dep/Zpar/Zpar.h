#ifndef _ZPAR_H
#define _ZPAR_H

#include <string>
#include <vector>
#include <Base_DepPar.h>
#include <rapidjson/document.h>
#include <utility>
#include "definitions.h"
#include "depparser.h"
#include "reader.h"
#include "writer.h"
#include "stdlib.h"

using namespace TARGET_LANGUAGE;


    class Zpar: public Base_DepPar {
    public:
        Zpar();
        ~Zpar();
        Zpar(const rapidjson::Document &config);
        std::vector<Dependency_TreeNode> depparser(std::vector<std::pair<std::string,std::string>> const &sentence) const;
        bool load();
        void train(const std::string &dest_model);
        bool save(std::string const &model_path) ;
    private:
        std::string modelfile;
        std::string corpus_path;
        int num_iterations;
        CDepParser *Par;
    };

#endif
