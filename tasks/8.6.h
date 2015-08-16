#ifndef TASK_8_6_H
#define TASK_8_6_H
#include <cstring>

template <typename T>
auto maxn(T ar[], int n) -> T{
    T maxT = ar[0];
    T temp;
    for(int i=0;i<n;i++){
        temp = ar[i];
        maxT = maxT<temp ? temp:maxT;
    }
    return maxT;
}

template<> auto maxn<char*>(char* ar[], int n) -> char*{
        using namespace std;
        char* Nmax = ar[0];
        int maxlen = strlen(Nmax);
        for(int i=0; i<n; i++){
            if(strlen(ar[i])>maxlen){
                Nmax = ar[i];
                maxlen = strlen(ar[i]);
            }
        }
        return Nmax;
    }

#endif // TASK_8_6_H
