#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, M, Y;
    vector<pair<int, int>> PDate;
    cin >> n >> m;

    while (n--)
    {
        cin >> Y >> M;
        PDate.push_back({Y, M});
    }

    sort(PDate.begin(), PDate.end());

    while (m--)
    {
        cin >> Y >> M;
        auto lwb = lower_bound(PDate.begin(), PDate.end(), make_pair(Y, M));
        auto upb = upper_bound(PDate.begin(), PDate.end(), make_pair(Y, M));

        if (upb == PDate.begin())
            cout << "-1 -1 ";
        else if (upb == lwb)
            cout << (lwb - 1)->first << " " << (lwb - 1)->second << " ";
        else
            cout << "0 0 ";
    }

    return 0;
}