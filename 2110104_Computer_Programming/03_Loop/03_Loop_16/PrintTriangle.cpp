#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n * 2 - 1; j++)
        {
            if (i == 1 || i == j || j == n * 2 - i)
                cout << '*';
            else if (j <= n * 2 - 1 - i)
                cout << '.';
            else
                cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}