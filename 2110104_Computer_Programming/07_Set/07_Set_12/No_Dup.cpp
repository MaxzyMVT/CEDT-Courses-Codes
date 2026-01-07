#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    set<int> S;
    while (cin >> n)
    {
        if (S.find(n) != S.end())
        {
            cout << S.size() + 1;
            return 0;
        }
        S.insert(n);
    }

    cout << -1;

    return 0;
}