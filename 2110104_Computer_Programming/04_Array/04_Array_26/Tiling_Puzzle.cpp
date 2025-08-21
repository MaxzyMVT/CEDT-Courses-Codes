#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, row = -1, blank_row, inv_cnt = 0;
    int A[2000];
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        if (i % n == 0)
            row++;

        cin >> A[i];
        if (A[i] == 0)
            blank_row = row;
    }

    for (int i = 0; i < n * n; i++)
    {
        for (int j = i + 1; j < n * n; j++)
        {
            if (A[i] > A[j] && A[i] != 0 && A[j] != 0)
                inv_cnt++;
        }
    }

    bool valid = false;
    if (n % 2)
    {
        if (inv_cnt % 2 == 0)
            valid = true;
    }
    else
    {
        if (inv_cnt % 2 == 0 ^ blank_row % 2 == 0)
            valid = true;
    }

    if (valid)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}