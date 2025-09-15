#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    map<string, int> Limit;                            // Dept, Limit
    map<string, int> Cnt;                              // Dept, Count
    map<string, string> Result;                        // ID, Dept
    map<pair<double, string>, vector<string>> dChosen; // {score, ID}, List of chosen depts
    vector<string> studentIDs;

    int n;
    cin >> n;
    while (n--)
    {
        string dept;
        int limit;
        cin >> dept >> limit;
        Limit[dept] = limit;
    }

    cin >> n;
    while (n--)
    {
        string ID, dA, dB, dC, dD;
        double score;
        cin >> ID >> score >> dA >> dB >> dC >> dD;

        studentIDs.push_back(ID);
        dChosen[{-score, ID}] = {dA, dB, dC, dD};
    }

    for (auto [data, depts] : dChosen)
    {
        auto [neg_score, ID] = data;
        for (string dept : depts)
        {
            if (Cnt[dept] >= Limit[dept])
                continue;
            Cnt[dept]++;
            Result[ID] = dept;
            break;
        }
    }

    sort(studentIDs.begin(), studentIDs.end());

    for (string ID : studentIDs)
        cout << ID << " " << Result[ID] << "\n";

    return 0;
}