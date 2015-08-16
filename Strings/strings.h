#ifndef STRINGS_H
#define STRINGS_H

#include <vector>
#include <string>
#include <sstream>

class Strings{
    private:
        std::string st;
        std::vector<std::string> stVec;
    public:
        template <typename T>
        std::string to_string(T inp)
        {
            std::ostringstream ss;
            ss << inp;
            return ss.str();
        }
        Strings(): st("")
        { }
        Strings(const std::string inp): st(inp)
        { }
        void show();
        void showVec();
        int addVec(const std::string);
        int setStrings(const std::string);

    };


#endif // STRINGS_H
