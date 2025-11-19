#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define Pos pair<int, int>

bool isThreat(Pos A, Pos B)
{
    auto [x1, y1] = A;
    auto [x2, y2] = B;

    return x1 == x2 || y1 == y2 || x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2;
}

int cntNQueen(int pos, vector<Pos> &Queen)
{
    int n = Queen.size();
    if (pos == n)
        return 1;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = pos;
        bool isValid = true;
        for (int q = 0; q < pos; q++)
        {
            if (isThreat({i, j}, Queen[q]))
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            Queen[pos] = {i, j};
            cnt += cntNQueen(pos + 1, Queen);
        }
    }
    return cnt;
}

int nQueen(int n)
{
    vector<Pos> Queen(n);
    return cntNQueen(0, Queen);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << nQueen(n);

    return 0;
}
