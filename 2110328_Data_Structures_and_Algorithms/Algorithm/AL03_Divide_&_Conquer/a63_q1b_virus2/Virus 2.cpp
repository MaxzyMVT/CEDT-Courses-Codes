#include <iostream>
#include <vector>
using namespace std;

bool isDIVOC20(vector<bool> &DNA, int st, int en, int &cnt);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, k;
    cin >> q >> k;

    while (q--)
    {
        vector<bool> DNA;
        int n = 1 << k;
        bool base;

        for (int i = 0; i < n; i++)
            cin >> base, DNA.push_back(base);

        int cnt = 0;
        cout << (isDIVOC20(DNA, 0, n, cnt) ? "yes\n" : "no\n");
    }

    return 0;
}

bool isDIVOC20(vector<bool> &DNA, int st, int en, int &cnt)
{
    int siz = en - st;
    if (siz < 2 || siz % 2 == 1)
        return false;
    if (siz == 2)
    {
        cnt = DNA[st] + DNA[st + 1];
        return true;
    }

    int cntL = 0, cntR = 0;
    int mid = (st + en) / 2;

    bool validA = isDIVOC20(DNA, st, mid, cntL);
    bool validB = isDIVOC20(DNA, mid, en, cntR);
    cnt = cntL + cntR;

    return validA && validB && abs(cntL - cntR) <= 1;
}
