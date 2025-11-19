#include <iostream>
#include <list>
#include <utility>
#include <queue>
using namespace std;

#define ll long long
#define val first
#define uid second
#define MinHeap priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>

int main()
{
    ll pMod = 0;
    list<pair<ll, int>> shopList;
    MinHeap pq;

    int n, q, ID = 0;
    cin >> n >> q;

    vector<bool> isValid(n + q);

    while (n--)
    {
        ll p;
        cin >> p;
        shopList.push_back({p, ID});
        pq.push({p, ID});
        isValid[ID++] = true;
    }

    for (int i = 1; i <= q; i++)
    {
        char com;
        ll p;
        cin >> com;

        if (com == '1')
        {
            cin >> p;
            p -= pMod;
            shopList.push_back({p, ID});
            pq.push({p, ID});
            isValid[ID++] = true;
        }
        else if (com == '2')
        {
            while (!shopList.empty() && !isValid[shopList.front().uid])
                shopList.pop_front();
            isValid[shopList.front().uid] = false;
            shopList.pop_front();
        }
        else if (com == '3')
        {
            while (!shopList.empty() && !isValid[shopList.back().uid])
                shopList.pop_back();
            isValid[shopList.back().uid] = false;
            shopList.pop_back();
        }
        else if (com == '4')
        {
            cin >> p;
            pMod += p;
        }
        else if (com == '5')
        {
            cin >> p;
            while (!pq.empty())
            {
                auto [v, id] = pq.top();
                if (v + pMod >= p)
                    break;
                pq.pop();
                isValid[id] = false;
            }
        }
        else if (com == '6')
        {
            cin >> p;

            while (!shopList.empty() && !isValid[shopList.back().uid])
                shopList.pop_back();
            while (!shopList.empty() && !isValid[shopList.front().uid])
                shopList.pop_front();

            auto en = shopList.end();
            ll deletedSum = 0;
            ll t = p;
            while (t--)
            {
                --en;
                if (!isValid[en->uid])
                {
                    t++;
                    continue;
                }
                isValid[en->uid] = false;
                deletedSum += en->val;
            }
            shopList.erase(en, shopList.end());

            ll pNew = deletedSum + pMod * (p - 1);
            shopList.push_front({pNew, ID});
            pq.push({pNew, ID});
            isValid[ID++] = true;
        }
    }

    auto it = shopList.begin();
    auto en = shopList.end();

    ll siz = 0, pSum = 0;
    while (it != en)
    {
        if (isValid[it->uid])
        {
            siz++;
            pSum += it->val;
        }
        ++it;
    }

    cout << siz << " " << pSum + pMod * siz;

    return 0;
}