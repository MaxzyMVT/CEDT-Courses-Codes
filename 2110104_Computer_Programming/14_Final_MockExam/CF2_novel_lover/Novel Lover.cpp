#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
    set<pair<int, string>> validNovels;
    int minLeft = 101;
    int money, n;

    cin >> money >> n;
    while (n--)
    {
        string name;
        int cnt = 0, eps, currMoney = money;

        cin >> name >> eps;
        for (int i = 1; i <= eps; i++)
        {
            int price;
            cin >> price;
            if (currMoney >= price)
            {
                currMoney -= price;
                cnt++;
            }
            else
                currMoney = 0;
        }
        if (cnt > 0)
        {
            int left = eps - cnt;
            if (left < minLeft)
            {
                minLeft = left;
                validNovels.clear();
                validNovels.insert({-n, name});
            }
            else if (left == minLeft)
            {
                validNovels.insert({-n, name});
            }
        }
    }

    if (validNovels.empty())
        cout << "FIND SOMETHING FREE\n";
    else
        for (auto &[idx, name] : validNovels)
            cout << name << "\n";

    return 0;
}