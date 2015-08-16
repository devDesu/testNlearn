#include "7.10.h"

const double* add(double x, double y){
        double res = x+y;
        return &res;
    }

const double* dec(double x, double y){
        double res = x-y;
        return &res;
    }

double calculate(double on, double tw, const double*(*func[2])(double, double)){
        return (*func[0](on,tw))*(*func[1](on, tw));
    }

void test710(){
    const double *(*funcList[2])(double, double) = {add, dec};
    double q = calculate(1.0, 2.0, funcList);
}
