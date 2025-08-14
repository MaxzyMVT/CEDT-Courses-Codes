#include <iostream>
#include <string>
#define ull unsigned long long
using namespace std;

ull pow2(ull x, ull p)
{
    if (p == 0)
        return 1;
    else if (p == 1)
        return x;

    ull ans = pow2(x, p / 2);
    if (p % 2)
        return ans * ans * x;
    return ans * ans;
}

int main()
{
    unsigned long long st, en, cnt = 0;

    cin >> st >> en;

    int st_siz = to_string(st).size();
    int en_siz = to_string(en).size();

    int now_siz = en_siz - 1;
    while (now_siz - st_siz > 0)
    {
        cnt += now_siz * 9 * pow2(10, now_siz - 1);
        now_siz--;
    }

    if (en_siz != st_siz)
    {
        cnt += en_siz * (en - pow2(10, en_siz - 1) + 1);
        cnt += st_siz * (pow2(10, st_siz) - st);
    }
    else
        cnt += (en - st + 1) * st_siz;

    cout << cnt;

    return 0;
}