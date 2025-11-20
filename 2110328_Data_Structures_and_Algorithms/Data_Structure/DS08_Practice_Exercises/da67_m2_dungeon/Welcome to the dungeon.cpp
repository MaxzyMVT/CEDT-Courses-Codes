#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define MinHeap priority_queue<int, vector<int>, greater<int>>

int main()
{
    int N, D, T, Z;
    cin >> N >> D >> T >> Z;

    vector<MinHeap> items(Z);
    while (D--)
    {
        int item, w;
        cin >> w >> item;
        items[item].push(w);
    }

    int cnt = 0;
    while (N--)
    {
        int q;
        cin >> q;

        bool isAble = true;
        while (q--)
        {
            int item;
            cin >> item;

            if (items[item].empty())
            {
                isAble = false;
                break;
            }

            int cost = items[item].top();
            items[item].pop();

            T -= cost;
            if (T < 0)
            {
                isAble = false;
                break;
            }
        }
        if (!isAble)
            break;
        cnt++;
    }

    cout << cnt;

    return 0;
}