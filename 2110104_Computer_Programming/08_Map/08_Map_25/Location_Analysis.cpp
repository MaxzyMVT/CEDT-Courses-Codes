#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    map<int, string> ID;         // Order, ID
    map<string, int> ORDER;      // ID, Order
    map<int, set<string>> towns; // Order, Set of towns

    string id, town;
    int n, cnt = 1;
    bool isFound = false;

    cin >> n;
    while (n--)
    {
        string id, town;
        cin >> id >> town;
        ORDER[id] = cnt;
        ID[cnt] = id;

        while (town != "*")
        {
            towns[cnt].insert(town);
            cin >> town;
        }

        cnt++;
    }

    cin >> id;
    auto T = towns[ORDER[id]];
    for (auto [cnt, other_T] : towns)
    {
        string other_id = ID[cnt];
        if (id == other_id)
            continue;

        for (string town : T)
        {
            if (other_T.find(town) != other_T.end())
            {
                cout << ">> " << other_id << "\n";
                isFound = true;
                break;
            }
        }
    }

    if (!isFound)
        cout << ">> Not Found\n";

    return 0;
}