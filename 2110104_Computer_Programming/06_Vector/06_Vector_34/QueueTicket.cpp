#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> Queue;
    pair<int, int> Current_Order;
    int current_ticket = 0;
    int completed_order = 0;
    double qtime_sum = 0;

    string in;
    int t, n;

    cin >> n;
    cin >> in >> t;
    current_ticket = t;

    while (--n)
    {
        cin >> in;
        if (in == "next")
        {
            cout << ">> call " << Queue.front().first << "\n";
            Current_Order = Queue.front();
            Queue.erase(Queue.begin());
            continue;
        }
        else if (in == "avg_qtime")
        {
            cout << ">> avg_qtime " << round(qtime_sum / completed_order * 100.0) / 100.0 << "\n";
            continue;
        }

        cin >> t;
        if (in == "new")
        {
            cout << ">> ticket " << current_ticket << "\n";
            Queue.push_back({current_ticket++, t});
        }
        else if (in == "order")
        {
            int current_ticket = Current_Order.first;
            int waiting_time = t - Current_Order.second;

            cout << ">> qtime " << current_ticket << " " << waiting_time << "\n";

            qtime_sum += waiting_time;
            completed_order++;
        }
    }

    return 0;
}