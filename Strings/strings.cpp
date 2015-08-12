#include "strings.h"
#include <exception>
#include <iostream>

void Strings::show(){
        using namespace std;
        cout<<st<<endl;
    }

void Strings::showVec(){
        using namespace std;
        for(string i: stVec){
            cout<<i<<endl;
        }
    }

int Strings::setStrings(const std::string inp){
        using namespace std;
        try{
            st = inp;
            return 1;
        }
        catch(const exception& e){
            return 0;
        }
    }

int Strings::addVec(const std::string inp){
        using namespace std;
        try{
            stVec.push_back(inp);
            return 1;
            }
            catch(const exception& e){
            return 0;
            }
    }
