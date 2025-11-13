#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 1, c = 1, n;

    cin >> n;
    while (n--)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << a << "\n";

    return 0;
}