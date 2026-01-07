#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<string, vector<string>> characters;
    vector<string> types;
    string name, type;

    while (cin >> name >> type)
    {
        if (characters.find(type) == characters.end())
            types.push_back(type);
        characters[type].push_back(name);
    }

    for (auto type : types)
    {
        cout << type << ": ";
        auto V = characters[type];
        for (auto e : V)
            cout << e << " ";
        cout << "\n";
    }

    return 0;
}