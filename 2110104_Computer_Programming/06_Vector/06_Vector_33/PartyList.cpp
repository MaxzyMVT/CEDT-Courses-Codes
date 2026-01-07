#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string in;
    double score_per_Rep;
    int sum_score = 0, sum_reps = 0;
    vector<tuple<double, int, int, string>> parties;
    // (Estimated Reps, #Reps, Score, Name)

    cin >> in;
    while (in != "END")
    {
        double score;
        cin >> score;

        parties.push_back({0, 0, -score, in});
        sum_score += score;

        cin >> in;
    }

    score_per_Rep = sum_score / 100.0;

    int n = parties.size();
    for (int i = 0; i < n; i++)
    {
        auto &party = parties[i];
        get<0>(party) = get<2>(party) / score_per_Rep;

        int rep = -get<0>(party);
        sum_reps += rep;
        get<1>(party) = -rep;
        get<0>(party) += rep;
    }

    sort(parties.begin(), parties.end());
    for (int i = 0; i < n; i++)
    {
        auto &party = parties[i];
        if (sum_reps < 100)
        {
            get<1>(party)--;
            sum_reps++;
        }
        get<0>(party) = 0;
    }

    sort(parties.begin(), parties.end());

    for (int i = 0; i < n; i++)
    {
        auto party = parties[i];
        int rep = get<1>(party);
        int score = get<2>(party);
        string name = get<3>(party);

        if (rep >= 0)
            break;

        cout << name << " " << -rep << " " << -score << "\n";
    }

    return 0;
}