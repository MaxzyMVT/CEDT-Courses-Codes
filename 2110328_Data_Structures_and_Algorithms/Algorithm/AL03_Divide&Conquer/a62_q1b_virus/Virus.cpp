#include <iostream>
#include <vector>
using namespace std;

bool isDIVOC(vector<bool> &DNA, int st, int en);
bool isMutatedDIVOC(vector<bool> &DNA, int st, int en);

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

        cout << (isDIVOC(DNA, 0, n) ? "yes\n" : "no\n");
    }

    return 0;
}

bool isDIVOC(vector<bool> &DNA, int st, int en)
{
    int siz = en - st;
    if (siz < 2 || siz % 2 == 1)
        return false;
    if (siz == 2)
        return !DNA[st] && DNA[st + 1];

    int mid = (st + en) / 2;
    bool validA = isDIVOC(DNA, st, mid) || isMutatedDIVOC(DNA, st, mid);
    if (!validA)
        return false;
    return isDIVOC(DNA, mid, en);
}

bool isMutatedDIVOC(vector<bool> &DNA, int st, int en)
{
    int siz = en - st;
    if (siz < 2 || siz % 2 == 1)
        return false;
    if (siz == 2)
        return DNA[st] && !DNA[st + 1];

    int mid = (st + en) / 2;
    bool validA = isMutatedDIVOC(DNA, st, mid);
    if (!validA)
        return false;
    return isMutatedDIVOC(DNA, mid, en) || isDIVOC(DNA, mid, en);
}
