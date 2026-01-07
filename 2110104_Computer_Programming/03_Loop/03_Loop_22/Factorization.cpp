#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n, i = 2;
    cin >> n;

    while (n > 1 && i <= n)
    {
        while (n % i == 0)
        {
            n /= i;
            cout << i;
            if (n != 1)
                cout << "*";
        }
        i++;
    }

    return 0;
}