#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> V;
    int n, a;
    bool isFront = false;

    cin >> n >> a;

    while (a != -1)
    {
        if (isFront)
            V.insert(V.begin(), a);
        else
            V.push_back(a);
        isFront ^= 1;
        cin >> a;
    }

    n = V.size();

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << V[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}