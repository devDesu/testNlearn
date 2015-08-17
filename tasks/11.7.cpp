#include "11.7.h"

complex complex::operator*(const complex& c){
    complex ret;
    ret.real = real*c.real-imaginary*c.imaginary;
    ret.imaginary = real*c.imaginary+imaginary*c.real;
    return ret;
}

complex operator*(const double x, const complex& c){
    return complex(c.real*x, c.imaginary*x);
}

complex operator*(const complex& c, const double x){
    return complex(c.real*x, c.imaginary*x);
}

complex complex::operator-(const complex& c){
    complex ret;
    ret.real = real - c.real;
    ret.imaginary = imaginary - c.imaginary;
    return ret;
}

complex complex::operator+(const complex& c){
    complex ret;
    ret.real = real + c.real;
    ret.imaginary = imaginary + c.imaginary;
    return ret;
}

complex complex::operator~(){
    return complex(real, -imaginary);
}

std::ostream& operator<<(std::ostream& os, const complex& c){
    os<<"Real: "<<c.real<<" imaginary: "<<c.imaginary<<std::endl;
    return os;
}
std::istream& operator>>(std::istream& os, complex& c){
    double dbl;
    std::cout<<"Enter real part:";
    os>>dbl;
    c.real = dbl;
    std::cout<<"Enter imaginary part:";
    os>>dbl;
    c.imaginary = dbl;
    return os;
}

void test117(){
    using std::cout;
    using std::cin;
    complex a(3.0, 4.0);
    complex c;
    cout<<a<<c;
    cin>>c;
    cout<<c;
    cout<<~c;
    cout<<a+c;
    cout<<a*c;
    cout<<3*a;
}
