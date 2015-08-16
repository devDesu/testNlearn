#include "9.4.h"
#include <iostream>
#include <limits>

namespace SALES{
    void setSales(Sales& s, const double ar[], int n){
            std::cout<<"Waiting for modding";
        }

    void setSales(Sales& s){
        int temp;
        int sum=0;
        s.max = 0;
        s.min = std::numeric_limits<int>::max();
            for(int i;i<QUARTERS;i++){
                std::cout<<"Enter Quarter value: ";
                std::cin>>temp;
                s.sales[i]=temp;
                if(s.max<temp) s.max=temp;
                if(s.min>temp) s.min=temp;
                sum+=temp;
            }
            s.avg = sum/4.0;
        }
}
