#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> nicknames, names;

    int n;
    cin >> n;
    while (n--)
    {
        string name, nickname;
        cin >> name >> nickname;
        nicknames[name] = nickname;
        names[nickname] = name;
    }

    cin >> n;
    while (n--)
    {
        string in;
        cin >> in;
        if (nicknames.find(in) != nicknames.end())
            cout << nicknames[in] << "\n";
        else if (names.find(in) != names.end())
            cout << names[in] << "\n";
        else
            cout << "Not found\n";
    }

    return 0;
}