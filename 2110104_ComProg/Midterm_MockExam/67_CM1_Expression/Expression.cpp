#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14125

int main()
{
    double x, result;

    cin >> x;

    double x_rad = x / 180 * PI;

    result = sqrt(x * x + pow(cos(x_rad), 2)) / (sin(x_rad) + (pow(cos(x_rad), 3) / (x * x + 1)));

    cout << fixed << setprecision(1) << result;

    return 0;
}