#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string, string> father;

    int n, m;
    cin >> n >> m;

    string A, B;

    while (n--)
        cin >> A >> B, father[B] = A;

    auto en = father.end();
    while (m--)
    {
        cin >> A >> B;

        if (A == B)
        {
            cout << "NO\n";
            continue;
        }

        auto p = father.find(A);
        auto q = father.find(B);

        if (p != en && q != en)
        {
            p = father.find(p->second);
            q = father.find(q->second);

            if (p != en && q != en && p->second == q->second)
            {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }

    return 0;
}