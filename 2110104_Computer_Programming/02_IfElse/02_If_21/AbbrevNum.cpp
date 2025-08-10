#include <iostream>
#include <cmath>
using namespace std;

int main() {

    unsigned long long sub;
    double display;
    cin >> sub;

    if(sub < 1000)
        cout << sub << "\n";
    else if(sub < 1000000)
    {
        display = round(sub / 100.0)/10.0;
        if(display >= 10)
            display = round(display);
        cout << display << "K";
    }
    else if(sub < 1000000000)
    {
        display = round(sub / 100000.0)/10.0;
        if(display >= 10)
            display = round(display);
        cout << display << "M";
    }
    else
    {
        display = round(sub / 100000000.0)/10.0;
        if(display >= 10)
            display = round(display);
        cout << display << "B";
    }

    return 0;
}