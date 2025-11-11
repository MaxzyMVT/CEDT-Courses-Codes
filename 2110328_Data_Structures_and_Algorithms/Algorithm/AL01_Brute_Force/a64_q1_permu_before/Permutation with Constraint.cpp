#include <iostream>
#include <vector>
using namespace std;

void printPermut(int pos, vector<int> &V, vector<bool> &U, vector<int> &Before)
{
    if (pos == V.size())
    {
        for (int e : V)
            cout << e << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < V.size(); i++)
    {
        if (U[i] || (Before[i] != -1 && !U[Before[i]]))
            continue;
        U[i] = true;
        V[pos] = i;
        printPermut(pos + 1, V, U, Before);
        U[i] = false;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> Before(n, -1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        Before[b] = a;
    }

    vector<int> V(n);
    vector<bool> U(n);

    printPermut(0, V, U, Before);

    return 0;
}