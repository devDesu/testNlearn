//#include "Strings/strings.h"
//#include "tasks/7.10.h"
//#include "tasks/8.6.h"
//#include "tasks/9.4.h"
//#include "tasks/10.8.h"
//#include "tasks/11.7.h"
//#include "test/inherit.h"
//#include "tasks/12.4.h"
//#include "tasks/13.4.h"
#include "tasks/14.5.h"
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
    test145();
    //getline(cin, temp);
    //Strings test(temp);

    return 0;
}
