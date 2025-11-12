#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m;

    vector<int> V;
    while (n--)
        cin >> a, V.push_back(a);

    while (m--)
    {
        cin >> a;
        int l = 0, r = V.size();
        int mid = (l + r) / 2;
        while (l < r)
        {
            if (V[mid] == a)
                break;
            if (V[mid] > a)
                r = mid;
            else
                l = mid + 1;
            mid = (l + r) / 2;
        }

        if (V[mid] > a)
            if (mid - 1 < 0)
                cout << "-1\n";
            else
                cout << V[mid - 1] << "\n";
        else if (mid >= V.size())
            cout << V.back();
        else
            cout << V[mid] << "\n";
    }

    return 0;
}
