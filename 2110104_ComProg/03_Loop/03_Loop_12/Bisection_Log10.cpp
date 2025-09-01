#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, x, left, right;

    cin >> a;

    left = 0;
    right = a;
    x = (left + right) / 2.0;

    while (abs(a - pow(10, x)) > 1e-10 * max(a, pow(10, x)))
    {
        if (pow(10, x) > a)
            right = x;
        else
            left = x;
        x = (left + right) / 2.0;
    }

    cout << x;

    return 0;
}