#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
    unordered_map<string, set<string>> adjacents; // Station, set of Adjacent Stations
    set<string> reachables;

    string inA, inB;
    cin >> inA;
    while (cin >> inB)
    {
        adjacents[inA].insert(inB);
        adjacents[inB].insert(inA);
        cin >> inA;
    }
    adjacents[inA].insert(inA);

    for (auto station : adjacents[inA])
        reachables.insert(station);

    auto tmp = reachables;
    for (auto station : tmp)
        for (auto next_station : adjacents[station])
            reachables.insert(next_station);

    for (auto station : reachables)
        cout << station << "\n";

    return 0;
}