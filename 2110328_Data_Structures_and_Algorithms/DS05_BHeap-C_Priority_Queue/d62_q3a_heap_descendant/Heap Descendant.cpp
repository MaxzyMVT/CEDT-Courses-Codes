#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> V;
    int n, a;
    cin >> n >> a;

    V.push_back(a);
    for (int i = 0; a * 2 + 1 < n; a = V[++i])
    {
        V.push_back(a * 2 + 1);
        if (a * 2 + 2 < n)
            V.push_back(a * 2 + 2);
    }

    cout << V.size() << "\n";
    for (auto e : V)
        cout << e << " ";

    return 0;
}