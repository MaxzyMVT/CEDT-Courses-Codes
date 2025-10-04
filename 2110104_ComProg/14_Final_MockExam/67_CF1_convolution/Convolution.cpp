#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<long long, long long> X, H;
    long long M, K, a, b, n, p;

    cin >> M >> K >> a >> b;
    while (M--)
    {
        cin >> n >> p;
        X[n] = p;
    }
    while (K--)
    {
        cin >> n >> p;
        H[n] = p;
    }

    for (long long i = a; i <= b; i++)
    {
        long long sum = 0;
        for (auto [key, val] : X)
        {
            sum += val * H[i - key];
        }
        cout << sum << " ";
    }

    return 0;
}