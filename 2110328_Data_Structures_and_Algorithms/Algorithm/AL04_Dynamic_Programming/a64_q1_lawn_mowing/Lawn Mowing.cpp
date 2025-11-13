#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> A(1), QS(1);
    int n, m, k, a;

    cin >> n >> m >> k;

    while (n--)
        cin >> a, A.push_back(a), QS.push_back(a);

    for (int i = 1; i < A.size(); i++)
    {
        QS[i] += QS[i - 1] + k;
        A[i] += A[i - 1];
    }

    while (m--)
    {
        int st;
        ll budget;
        cin >> st >> budget;
        st++;

        budget += QS[st - 1];

        auto fnd = upper_bound(QS.begin() + st, QS.end(), budget);
        int en = fnd - QS.begin() - 1;

        cout << A[en] - A[st - 1] << "\n";
    }
    return 0;
}