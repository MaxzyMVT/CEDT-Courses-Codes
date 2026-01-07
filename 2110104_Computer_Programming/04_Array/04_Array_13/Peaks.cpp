#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;

    double y[100];

    for (int i = 0; i < n; i++)
        cin >> y[i];

    for (int i = 0; i < n; i++)
        if (i != 0 && i != n - 1 && y[i] > y[i - 1] && y[i] > y[i + 1])
            cnt++;

    cout << cnt;

    return 0;
}