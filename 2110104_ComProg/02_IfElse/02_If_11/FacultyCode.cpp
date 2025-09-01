#include <iostream>
#include <cmath>
using namespace std;

int main() {

    string in;
    cin >> in;

    if(in >= "20" && in <= "40" && in.size() == 2 && stoi(in) >= 20 && stoi(in) <= 40 || in == "01" || in == "02" || in == "51" || in == "53" || in == "55" || in == "58")
        cout << "OK";
    else
        cout << "Error";

    return 0;
}