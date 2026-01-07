#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string in;
    vector<string> V;

    cin >> in;

    in += "$";

    int n = in.size();

    for (int i = 0; i < n; i++)
    {
        V.push_back(in);
        in += in.front();
        in.erase(0, 1);
    }

    sort(V.begin(), V.end());

    for (string e : V)
        cout << e.back();
}