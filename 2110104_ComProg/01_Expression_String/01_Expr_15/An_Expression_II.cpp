#include <iostream>
#include <cmath>

using namespace std;

int main() {


    double x;

    cin >> x;

    double ans = pow(x, sqrt(log((x+1)*(x+1)))) / (10-x);

    cout << round(ans * 1e6) / 1e6 << "\n";
     
    return 0;
}