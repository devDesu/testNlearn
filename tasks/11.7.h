#ifndef TASK_11_7_H_INCLUDED
#define TASK_11_7_H_INCLUDED
#include <iostream>

class complex{
private:
    double real;
    double imaginary;
public:
    complex(double re=0, double im=0): real(re), imaginary(im)
    {
    }
    complex operator*(const complex&);
    complex operator-(const complex&);
    complex operator+(const complex&);
    complex operator~();
    friend complex operator*(const complex&, double);
    friend complex operator*(const double, const complex&);
    friend std::ostream& operator<<(std::ostream&, const complex&);
    friend std::istream& operator>>(std::istream&, complex&);
};

void test117();
#endif // 11_7_H_INCLUDED
