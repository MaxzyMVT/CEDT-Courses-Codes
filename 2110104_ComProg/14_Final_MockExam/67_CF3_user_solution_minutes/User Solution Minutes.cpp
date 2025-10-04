#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    map<string, set<int>> times;
    string in;
    int n, k, a;

    cin >> n >> k;
    while (n--)
    {
        cin >> in >> a;
        times[in].insert(a);
    }

    int cnt = 0;
    for (auto [id, time] : times)
    {
        if (time.size() == k)
            cnt++;
    }
    cout << cnt;

    return 0;
}