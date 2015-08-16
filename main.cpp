//#include "Strings/strings.h"
//#include "tasks/7.10.h"
//#include "tasks/8.6.h"
//#include "tasks/9.4.h"
#include "tasks/10.8.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

template <typename T>
void echo(T& p){
    std::cout<<p;
    }

enum letters{A, B, C};

int main()
{
    using namespace std;
    // freopen("file", "a+", stdin); REPLACE STDIN WITH FILE
    string temp = "";
    //getline(cin, temp);
    //Strings test(temp);
    {
    List<double> test2;
    for(int i=0;i<100;i++)
        test2.add(i+i*i+0.5);
    test2.pop(5);
    test2.visit(func);
    test2.set(0, 12);
    test2[1] = -1;
    //cout<<test2[0]<<endl;
    cout<<test2;
    test2.show();
    }

    return 0;
}
