//
// Created by 王鹏飞 on 16/3/1.
//

#ifndef POSTAGGER_PREPROCESSOR_H
#define POSTAGGER_PREPROCESSOR_H

#include <string>
#include <vector>


class PreProcessor {
public:
   std:: string modify_file_for_train(const std::string &rawfile);

    //return modefied file for crf train;
    int train_model(const std::string &_template, const std::string &stand_file, const std::string &modelname);

    int test_model(const std::string &model, const std::string &stand_file, const std::string &dest_file);

    std::vector<std::pair<std::string,std::string>> model_file_for_tag_ret(const std::string &tmp);
};

#endif //POSTAGGER_PREPROCESSOR_H
