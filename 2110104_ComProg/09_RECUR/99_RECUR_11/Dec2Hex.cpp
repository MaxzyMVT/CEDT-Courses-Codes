#include <iostream>
using namespace std;

string dec2hex(int d)
{
    if (d < 16)
    {
        string hex = (d < 10 ? "0" : "A");
        d %= 10;
        hex[0] += d;
        return hex;
    }
    return dec2hex(d / 16) + dec2hex(d % 16);
}

int main()
{
    int d;
    while (cin >> d)
    {
        cout << d << " -> " << dec2hex(d) << endl;
    }
    return 0;
}
