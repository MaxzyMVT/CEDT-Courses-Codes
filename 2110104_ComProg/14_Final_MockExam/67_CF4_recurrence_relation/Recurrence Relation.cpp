#include <iostream>
using namespace std;

int S(int n, int k)
{ // Stirling numbers of the second kind
    if (n == 0 && k == 0)
        return 1;
    if (k == 0 || n == 0)
        return 0;
    return k * S(n - 1, k) + S(n - 1, k - 1);
}

int B(int n)
{ // Bell number
    if (n == 0)
        return 1;

    int fac[13];
    fac[0] = 1;
    for (int i = 1; i <= 12; i++)
        fac[i] = fac[i - 1] * i;

    int sum = 0;
    for (int k = 0; k <= n - 1; k++)
    {
        sum += fac[n - 1] / fac[n - 1 - k] / fac[k] * B(k); // C(n-1, r) * B(k)
    }
    return sum;
}

int T(int n, int x)
{ // Chebyshev polynomials
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    return 2 * x * T(n - 1, x) - T(n - 2, x);
}

int main()
{
    string fn;
    int i, j;
    while (cin >> fn)
    {
        if (fn == "S")
        {
            cin >> i >> j;
            printf("S(%d, %d) = %d\n", i, j, S(i, j));
        }
        else if (fn == "B")
        {
            cin >> i;
            printf("B(%d) = %d\n", i, B(i));
        }
        else if (fn == "T")
        {
            cin >> i >> j;
            printf("T(%d, %d) = %d\n", i, j, T(i, j));
        }
    }
    return 0;
}