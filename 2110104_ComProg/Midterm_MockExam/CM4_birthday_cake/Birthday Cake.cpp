#include <iostream>
using namespace std;

int main()
{
    int n, k, Mx = 0;
    int A[1001] = {};
    int SumLen[1001] = {};

    int pos = 1;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int now = A[i];
        int sum = 0;
        int len = 0;

        for (int j = i; j < min(i + k, n + 1); j++)
        {
            if (A[j] > now)
                break;
            len = j - i + 1;
            sum += A[j];
        }

        SumLen[i] = len;

        if (Mx < sum)
        {
            pos = i;
            Mx = sum;
        }
        else if (Mx == sum)
        {
            if (len > SumLen[pos])
            {
                pos = i;
            }
            else if (len == SumLen[pos])
            {
                for (int k = 0; k < len; k++)
                {
                    if (A[i] > A[pos])
                    {
                        pos = i;
                        break;
                    }
                    else if (A[i] < A[pos])
                    {
                        break;
                    }
                }
            }
        }
    }

    cout << Mx << "\n";

    for (int i = pos; i < pos + SumLen[pos]; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}