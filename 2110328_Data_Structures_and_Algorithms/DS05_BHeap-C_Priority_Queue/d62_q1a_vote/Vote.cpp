#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

int main()
{
    map<string, int> vote;
    priority_queue<int> pq;

    int n, m;
    cin >> n >> m;

    while (n--)
    {
        string in;
        cin >> in;
        vote[in]++;
    }

    for (auto &[name, cnt] : vote)
        pq.push(cnt);

    while (--m && pq.size() > 1)
        pq.pop();

    cout << pq.top();

    return 0;
}