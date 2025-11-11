#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> Q;
    vector<int> V;

    int n, k;
    cin >> n >> k;

    int t = k;
    Q.push(k * 2 + 1);
    Q.push(k * 2 + 2);

    for (int i = 0; i < n; i++)
    {
        if (i == t)
        {
            t = Q.front();
            Q.pop();
            Q.push(t * 2 + 1);
            Q.push(t * 2 + 2);
        }
        else
            V.push_back(i);
    }

    cout << V.size() << "\n";
    for (int e : V)
        cout << e << " ";

    return 0;
}