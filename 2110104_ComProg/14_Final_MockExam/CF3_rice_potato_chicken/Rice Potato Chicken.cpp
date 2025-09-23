#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, q;
    deque<long long> shopsP;
    long long sum = 0;

    cin >> n >> q;
    while (n--)
    {
        int a;
        cin >> a;
        shopsP.push_back(a);
    }
    while (q--)
    {
        int com, val;
        cin >> com;

        if (com == 2)
            shopsP.pop_front();
        else if (com == 3)
            shopsP.pop_back();
        else if (com == 1)
        {
            cin >> val;
            shopsP.push_back(val);
        }
        else if (com == 4)
        {
            cin >> val;
            for (long long &pop : shopsP)
                pop += val;
        }
        else if (com == 5)
        {
            cin >> val;
            for (int i = 0; i < shopsP.size(); i++)
            {
                if (shopsP[i] < val)
                {
                    shopsP.erase(shopsP.begin() + i);
                    i--;
                }
            }
        }
        else if (com == 6)
        {
            long long sum = 0;
            cin >> val;
            while (val-- && !shopsP.empty())
            {
                sum += shopsP.back();
                shopsP.pop_back();
            }
            shopsP.push_front(sum);
        }
    }

    for (auto pop : shopsP)
        sum += pop;

    cout << shopsP.size() << " " << sum << "\n";

    return 0;
}