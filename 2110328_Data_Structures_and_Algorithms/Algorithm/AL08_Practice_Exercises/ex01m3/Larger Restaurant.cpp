#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    cin >> n >> a;

    vector<int> T(n);

    for (int i = 0; i < n; i++)
        cin >> T[i];

    while (a--)
    {
        ll c;
        cin >> c;

        ll l = 0, r = c * 1000;
        ll mid = (l + r) / 2;

        while (l < r)
        {
            ll sum = 0;
            for (int t : T)
                sum += mid / t + 1;

            if (sum >= c)
                r = mid;
            else
                l = mid + 1;

            mid = (l + r) / 2;
        }

        cout << mid << "\n";
    }

    return 0;
}
