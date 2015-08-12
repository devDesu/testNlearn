#include <iostream>
#include "Strings/strings.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
    string temp;
    getline(cin, temp);
    Strings test(temp);
    test.addVec("test vec1");
    test.addVec("test vec 2");
    test.show();
    test.showVec();
    return 0;
}
