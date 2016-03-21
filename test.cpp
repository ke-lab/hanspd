//
// Created by 王鹏飞 on 16/3/20.
//

#include <iostream>

#define ELPP_DEFAULT_LOG_FILE "logs/hanspd-test-%datetime.log"

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#include "base_seger.h"
int main(){
    using namespace std;
    cout << "Hello, hanspd!" << endl;
}
