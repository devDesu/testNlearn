#ifndef STRINGS_H
#define STRINGS_H

#include <vector>
#include <string>

class Strings{
    private:
        std::string st;
        std::vector<std::string> stVec;
    public:
        Strings(): st("")
        { }
        Strings(const std::string inp): st(inp)
        { }
        void show();
        void showVec();
        int addVec(const std::string inp);
        int setStrings(const std::string inp);

    };


#endif // STRINGS_H
