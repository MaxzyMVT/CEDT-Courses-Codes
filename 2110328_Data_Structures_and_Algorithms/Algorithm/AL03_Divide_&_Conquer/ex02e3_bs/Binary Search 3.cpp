#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m;

    vector<int> V(1, -1);
    V.reserve(n + 1);
    while (n--)
        cin >> a, V.emplace_back(a);

    while (m--)
    {
        cin >> a;
        int l = 0, r = V.size() - 1;
        int mid = (l + r) / 2;
        while (l <= r)
        {
            if (V[mid] > a)
                r = mid - 1;
            else
                l = mid + 1;
            mid = (l + r) / 2;
        }
        cout << mid - 1 << "\n";
    }

    return 0;
}
