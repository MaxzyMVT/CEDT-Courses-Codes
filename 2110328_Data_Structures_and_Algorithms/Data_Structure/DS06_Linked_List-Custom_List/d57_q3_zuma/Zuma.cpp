#include <iostream>
#include <list>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::list<int> ls;
    int n, k, v, p;

    std::cin >> n >> k >> v;
    while (n--)
        std::cin >> p, ls.push_back(p);

    auto itf = ls.insert(std::next(ls.begin(), k), v);
    auto itl = next(itf);

    int cnt = 0;
    do
    {
        int val = *itf;
        cnt = 0;

        while (itf != --ls.begin() && *itf == val)
            itf--, cnt++;
        itf++;

        while (itl != ls.end() && *itl == val)
            itl++, cnt++;

        if (cnt >= 3)
        {
            itl = ls.erase(itf, itl);
            itf = prev(itl);
        }
    } while (cnt >= 3 && ls.size() >= 3 && *itf == *itl);

    for (int e : ls)
        std::cout << e << " ";

    return 0;
}
