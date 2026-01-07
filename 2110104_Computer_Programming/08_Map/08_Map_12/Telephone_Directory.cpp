#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> telephones, names;
    string in;

    int n;
    cin >> n;
    while (n--)
    {
        string name, surname, telephone;
        cin >> name >> surname >> telephone;

        name = name + " " + surname;

        telephones[name] = telephone;
        names[telephone] = name;
    }

    cin >> n;
    while (n--)
    {
        getline(cin >> ws, in);
        cout << in << " --> ";

        if (telephones.find(in) != telephones.end())
            cout << telephones[in] << "\n";
        else if (names.find(in) != names.end())
            cout << names[in] << "\n";
        else
            cout << "Not found\n";
    }

    return 0;
}