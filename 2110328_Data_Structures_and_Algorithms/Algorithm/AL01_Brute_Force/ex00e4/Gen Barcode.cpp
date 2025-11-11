#include <iostream>
#include <vector>
using namespace std;

void recur(int pos, string &B, vector<int> &cnt, vector<int> &lim)
{
    if (pos == B.size())
    {
        cout << B << "\n";
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (cnt[i] < lim[i])
        {
            cnt[i]++;
            B[pos] = '0' + i;
            recur(pos + 1, B, cnt, lim);
            cnt[i]--;
        }
    }
}

void printInterleaved(int a, int b)
{
    vector<int> cnt(2);
    vector<int> lim = {b - a, a};
    string B(b, '0');
    recur(0, B, cnt, lim);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    printInterleaved(a, b);

    return 0;
}