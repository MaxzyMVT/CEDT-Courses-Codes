#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string covertToTime(int seconds)
{
    int minutes = seconds / 60;
    seconds %= 60;

    return to_string(minutes) + ":" + to_string(seconds);
}

int main()
{
    // Type, Seconds
    unordered_map<string, int> times;
    vector<pair<int, string>> V;
    string name, type, Ftime;

    while (cin >> name >> name >> type >> Ftime)
    {
        int pos = Ftime.find(':');
        times[type] += stoi(Ftime) * 60 + stoi(Ftime.substr(pos + 1));
    }

    for (auto &[type, seconds] : times)
        V.push_back({-seconds, type});

    sort(V.begin(), V.end());

    int n = min(3, (int)V.size());
    for (int i = 0; i < n; i++)
    {
        auto &[seconds, type] = V[i];
        cout << type << " --> " << covertToTime(-seconds) << "\n";
    }

    return 0;
}