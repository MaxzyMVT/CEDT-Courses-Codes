#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string win, lose;
    set<string> W, L;
    while (cin >> win >> lose)
    {
        W.insert(win);
        L.insert(lose);
    }

    for (string e : L)
        W.erase(e);

    if (!W.empty())
        for (string e : W)
            cout << e << " ";
    else
        cout << "None";

    return 0;
}