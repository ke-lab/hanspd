//
// Created by 王鹏飞 on 16/3/8.
//

#include <tagger/crf/CRFTagger.h>
#include <fstream>
#include <boost/program_options.hpp>
using namespace boost::program_options;
int main(int argc,char *argv[]){

    options_description desc{"Options"};
    desc.add_options()
            ("help,h", "show help message")
            ("config,c", value<std::string>(), "config file")
            ("output,o",value<std::string>(),"output model name");
    //program options
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")) {
       std:: cout << desc << std::endl;
        exit(0);
    }
    if (!vm.count("config")) {
       std::cerr << "Must specify config file path." << std::endl;
       std:: cout << desc << std::endl;
        exit(1);
    }
    if (!vm.count("output")) {
        std::cerr << "Must specify output model path." << std::endl;
        std::cout << desc <<std::endl;
        exit(1);
    }

    std::string const config_file = vm["config"].as<std::string>();
    std::string const model_name = vm["output"].as<std::string>();

    std::ifstream in(config_file,std::ios::in);
    std::istreambuf_iterator<char> beg(in), end;
    std::string jsondata(beg, end);
    rapidjson::Document document;
    document.Parse(jsondata.c_str());
    Base_Tagger *p=Base_Tagger::create_Tagger(document,"CRF");
    p->train(model_name);
    return 0;
}
