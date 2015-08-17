//#include "Strings/strings.h"
//#include "tasks/7.10.h"
//#include "tasks/8.6.h"
//#include "tasks/9.4.h"
//#include "tasks/10.8.h"
//#include "tasks/11.7.h"
#include "tasks/12.4.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

template <typename T>
void echo(T& p)
{
    std::cout<<p;
}

enum letters {A, B, C};

int main()
{
    using namespace std;
    // freopen("file", "a+", stdin); REPLACE STDIN WITH FILE
    string temp = "";
    //List<int> test(3);
    //cout<<test;
    //test[2] = 2;
    //List<int> test2;
    //test2 = test;
    //cout<<test2;
    //getline(cin, temp);
    //Strings test(temp);
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.show();
    Item it;
    s.pop(it);
    s.show();
    return 0;
}
