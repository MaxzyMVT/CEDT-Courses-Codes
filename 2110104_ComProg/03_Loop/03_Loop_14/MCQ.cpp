#include <iostream>
#include <string>
using namespace std;

int main()
{
    string key, ans;
    int cnt = 0;

    cin >> key;
    getline(cin >> ws, ans);

    if (ans.size() < key.size())
    {
        cout << "Incomplete answer";
        return 0;
    }

    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] == ans[i])
            cnt++;
    }

    cout << cnt;

    return 0;
}