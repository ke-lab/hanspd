#ifndef _BASE_DEPPAR_H
#define _BASE_DEPPAR_H

#include <iostream>
#include <vector>

struct Dependency_TreeNode{
    std::string word;
    std::string tag;
    std::string label;
    int head;
};

class Base_DepPar {
public:
    virtual void train(const std::string &dest_model)=0;
    virtual bool load()=0;
    virtual std::vector<Dependency_TreeNode> depparser(std::vector<std::pair<std::string,std::string>> const &sentence) const = 0;
};
#endif
