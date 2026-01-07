#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    double weight, height;

    cin >> weight >> height;

    cout << setprecision(15) << sqrt(weight*height)/60.0 << "\n";
    cout << 0.024265 * pow(weight, 0.5378) * pow(height, 0.3964) << "\n";
    cout << 0.0333 * pow(weight, (0.6157 - 0.0188 * log10(weight))) * pow(height, 0.3) << "\n";

    return 0;
}