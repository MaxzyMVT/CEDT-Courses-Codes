#include <iostream>
#include <cmath>
using namespace std;

int main() {

    string in;
    cin >> in;

    string leading = in.substr(0, 2);

    if(in.size() == 10 && leading == "06" || leading == "08" || leading == "09")
        cout << "Mobile number";
    else
        cout << "Not a mobile number";

    return 0;
}