#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int yearBE, yearAD, rear, X;

    cin >> yearBE;
    yearAD = yearBE - 543;

    rear = yearAD % 100;

    X = rear + floor(rear/4.0) + 11;

    cout << X%7 << "\n";
     

    return 0;
}