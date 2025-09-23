#include <iostream>
#include <string>
using namespace std;

int main()
{

    long long n, sum = 0;
    string in;

    cin >> n;

    while (cin >> in)
    {
        sum += stoi(in.substr(1));
    }

    cout << sum * n;

    return 0;
}