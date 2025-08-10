#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double fac10 = 10.0*9*8*7*6*5*4*3*2;
    double PI = 3.14159;

    cout << ( PI - (fac10 / pow(8, 8)) + pow(log(9.7), 7.0/sqrt(71) - sin(40*PI/180.0)) ) / pow(1.2, cbrt(2.3));

    return 0;
}