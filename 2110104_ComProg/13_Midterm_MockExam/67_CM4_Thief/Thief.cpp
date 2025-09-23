#include <iostream>
#include <string>
using namespace std;

int main()
{

    int n, m, a, sum = 0, tar;
    int A[51];

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    tar = sum - m;

    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {

            if (A[i] + A[j] == tar)
            {
                cout << i - 1 << " " << A[i] << "\n";
                cout << j - 1 << " " << A[j] << "\n";
                return 0;
            }
        }
    }

    return 0;
}