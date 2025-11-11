#include <iostream>
#include <vector>
using namespace std;

void recur(int pos, string &B, bool valid, int cnt, int target)
{
    if (pos == B.size())
    {
        if (valid)
            cout << B << "\n";
        return;
    }

    if (pos >= B.size() - target + cnt + 1 && !valid)
        return;

    for (int i = 0; i < 2; i++)
    {
        int cnt_nx = i == 0 ? 0 : cnt + 1;
        bool valid_nx = valid || cnt_nx >= target ? true : false;
        B[pos] = i + '0';
        recur(pos + 1, B, valid_nx, cnt_nx, target);
    }
}

void printConsecutiveOnes(int siz, int target)
{
    string B(siz, '0');
    recur(0, B, false, 0, target);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    printConsecutiveOnes(a, b);

    return 0;
}