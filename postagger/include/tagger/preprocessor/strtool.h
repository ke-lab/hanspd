//
// Created by 王鹏飞 on 16/1/19.
//

#include <iostream>
#include <locale>
#include <codecvt>
    namespace strtool {
        extern std::string trim(const std::string &str);

        extern int split(const std::string &str, std::vector<std::string> &ret_, std::string sep = ",");

        extern std::string replace(const std::string &str, const std::string &src, const std::string &dest);

        static std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv;

        extern std::string To_UTF8(const std::u32string& from);

        extern std::string gen_filename(const std::string &suffix);

    }

