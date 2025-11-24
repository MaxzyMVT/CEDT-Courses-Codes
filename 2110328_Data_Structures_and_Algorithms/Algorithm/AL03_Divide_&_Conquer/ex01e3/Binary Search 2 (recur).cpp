#include <iostream>
#include <vector>
using namespace std;

template <typename Iterator, typename T>
Iterator pre_upper_bound(Iterator beg, Iterator end, T val)
{
    if (end - beg <= 1)
        return beg;

    size_t half = (end - beg) / 2;
    Iterator mid = beg + half;

    if (*mid <= val)
        return pre_upper_bound(mid, end, val);
    return pre_upper_bound(beg, mid, val);
}

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
        int val;
        cin >> val;
        cout << *pre_upper_bound(V.begin(), V.end(), val) << "\n";
    }

    return 0;
}