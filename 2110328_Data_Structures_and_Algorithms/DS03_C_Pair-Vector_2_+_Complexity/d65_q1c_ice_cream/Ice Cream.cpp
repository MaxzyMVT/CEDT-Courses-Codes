#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, start;
    vector<pair<int,int>> S;
    vector<int> Progress, Days;

    cin >> n >> m >> start;

    while(n--)
    {
        int a,s;
        cin >> a >> s;
        S.push_back({a,s});
    }


    S.push_back({0, start});  // limiter
    sort(S.begin(), S.end());
    S.push_back({200000, 0}); // limiter

    auto itr = S.begin();
    auto end = S.end();
    int day_curr = -1, saving_curr = 0, sum_saving = 0;


    while(itr != end)
    {
        auto [day, saving] = *itr;

        int len = day - day_curr - 1;
        int potential_sum = sum_saving + len * saving_curr; 

        Days.push_back(day-1);
        Progress.push_back(potential_sum);

        sum_saving = potential_sum;
        saving_curr = saving;
        day_curr = day - 1;

        itr++;
    }

    while(m--)
    {
        int P, X;
        cin >> P >> X;

        auto enough_idx = lower_bound(Progress.begin(), Progress.end(), P) - Progress.begin();

        int DayPrev = Days[enough_idx-1];
        int SavingPrev = S[enough_idx-1].second;
        int SumSavingPrev = Progress[enough_idx-1];

        int remaining_price = P - SumSavingPrev;
        int remaining_days = (remaining_price + SavingPrev - 1)/SavingPrev; // ceil(a/b)
        int total_days = DayPrev + remaining_days;

        if(total_days <= X)
        {
            cout << total_days << " ";
            continue;
        }
    
        auto loss_idx = lower_bound(Days.begin(), Days.end(), X) - Days.begin() - 1;
        int loss = Progress[loss_idx] + (X - Days[loss_idx]) * S[loss_idx].second;

        enough_idx = lower_bound(Progress.begin(), Progress.end(), P+loss) - Progress.begin() - 1;

        DayPrev = Days[enough_idx];
        SavingPrev = S[enough_idx].second;
        SumSavingPrev = Progress[enough_idx] - loss;
        
        remaining_price = P - SumSavingPrev;
        remaining_days = (remaining_price + SavingPrev - 1)/SavingPrev; // (a+b-1)/b == ceil(a/b)
        total_days = DayPrev + remaining_days;

        cout << total_days << " ";
    }


    return 0;
}