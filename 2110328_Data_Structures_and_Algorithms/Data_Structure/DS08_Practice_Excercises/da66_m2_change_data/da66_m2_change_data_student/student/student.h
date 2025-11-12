#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> ans;
    while (a.size())
    {
        auto V = a.top();
        a.pop();
        for (auto &q : V)
        {
            int qSiz = q.size();
            while (qSiz--)
            {
                int e = q.front();
                q.pop();

                if (e == from)
                    q.push(to);
                else
                    q.push(e);
            }
        }
        ans.push(V);
    }

    while (ans.size())
    {
        a.push(ans.top());
        ans.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for (auto &[key, p] : a)
    {
        auto &[pq, num] = p;
        if (num == from)
            num = to;

        std::vector<int> pqE;
        while (pq.size())
        {
            int e = pq.top();
            pq.pop();
            if (e == from)
                pqE.push_back(to);
            else
                pqE.push_back(e);
        }
        pq = std::priority_queue(pqE.begin(), pqE.end());
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> ans;

    for (auto p1 : a)
    {
        auto &[ls, mp] = p1;

        for (auto &e : ls)
            if (e == from)
                e = to;

        std::map<int, std::pair<int, string>> mp_new;
        for (auto &[key, p2] : mp)
        {
            if (p2.first == from)
                p2.first = to;
            if (key == from)
                mp_new[to] = p2;
            else
                mp_new[key] = p2;
        }

        ans.insert(std::make_pair(ls, mp_new));
    }
    a = ans;
}

#endif
