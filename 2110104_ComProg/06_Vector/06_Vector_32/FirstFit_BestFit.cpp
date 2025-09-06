#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // First element is the -1 * sum of subset's elements
    // Second element is the size of subset
    vector<vector<int>> V;
    bool first_fit = false;
    int a;

    string in;
    cin >> in;

    first_fit = in == "first";

    while (cin >> a)
    {
        // Create new subset contains only a at the back
        int n = V.size();
        V.push_back({-a, 1, a});
        int pos = n;
        int best = 100 - a;

        for (int i = 0; i < n; i++)
        {
            // Check if a is more suitable in other sebsets

            if (V[i][0] - a < -100) // Skip if this subset can't contain a
                continue;
            if (first_fit)
            {
                // First-Fit method
                V[i][0] = V[i][0] - a;
                V[i][1]++;
                V[i].push_back(a);
                V[n][1] = 0;
                break;
            }
            if (100 + V[i][0] - a < best)
            {
                // Best-Fit method
                V[pos][0] += a;
                V[pos][1]--;
                V[pos].pop_back();

                V[i][0] = V[i][0] - a;
                V[i][1]++;
                V[i].push_back(a);

                best = 100 + V[i][0];
                pos = i;
            }
        }
        // If a was moved to other subset, delete newly create subset
        if (V[n][1] == 0)
            V.pop_back();
    }

    // Sort number of elements in subset from lesser to greater
    for (auto &subset : V)
    {
        sort(subset.begin() + 1, subset.end());
    }

    // Sort sums of subset from greater to lesser (sum * -1)
    sort(V.begin(), V.end());

    for (auto &subset : V)
    {
        int n = subset.size();
        if (subset[1] > 0)
            for (auto i = 2; i < n; i++)
            {
                cout << subset[i] << " ";
            }
        cout << "\n";
    }

    return 0;
}