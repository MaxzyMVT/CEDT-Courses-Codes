#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m, st, en, num;
    int st_floor[100], en_floor[100];

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> num >> st >> en;
        st_floor[num] = st;
        en_floor[num] = en;
    }

    cin >> m;
    while (m--)
    {
        cin >> st >> en;
        int target_dir = st - en;
        int Mn = 1000;
        int best_lift = 1;

        // I STAY HERE
        if (target_dir == 0)
        {
            cout << 1;
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            int burden = 1000;
            int lift_dir = st_floor[i] - en_floor[i];

            // Lift stay still :)
            if (lift_dir == 0)
            {
                burden = abs(st - en_floor[i]) + abs(target_dir);
            }

            // (Target go same direction with lift AND stay between lift's route) OR target stay at lift's destination
            else if (lift_dir < 0 ^ target_dir > 0 && abs(st - st_floor[i]) + abs(st - en_floor[i]) == abs(lift_dir) || en_floor[i] == st)
            {
                burden = abs(en_floor[i] - en);
            }

            // Target doesn't HELP AT ALL
            else
            {
                burden = abs(st - en_floor[i]) + abs(target_dir);
            }

            if (burden < Mn)
            {
                Mn = burden;
                best_lift = i;
            }
        }

        cout << ">> " << best_lift << "\n";
    }

    return 0;
}