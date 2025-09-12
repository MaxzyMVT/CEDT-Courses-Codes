#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, a, cnt = 0;
    int A[201], B[201];

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            bool B[201] = {};

            bool isNotPerm = false;
            for (int k = j; k < j + i; k++)
            {
                if (isNotPerm = A[k] <= 0)
                    break;
                if (isNotPerm = B[A[k]])
                    break;
                B[A[k]] = true;
            }
            if (!isNotPerm)
                for (int k = 1; k <= i; k++)
                {
                    if (isNotPerm = !B[k])
                        break;
                }
            if (!isNotPerm)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}