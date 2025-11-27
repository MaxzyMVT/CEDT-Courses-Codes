#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, h, w, q;
    cin >> d >> h >> w;

    vector<vector<vector<int>>> V(h + 1, vector<vector<int>>(w + 1, vector<int>(d + 1)));

    for (int k = 1; k <= d; k++)
    {
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                // THE PRINCIPLE OF INCLUSION-EXCLUSION (PIE)
                cin >> V[i][j][k];
                V[i][j][k] += (V[i - 1][j][k] + V[i][j - 1][k] + V[i][j][k - 1]) - (V[i - 1][j - 1][k] + V[i][j - 1][k - 1] + V[i - 1][j][k - 1]) + (V[i - 1][j - 1][k - 1]);
            }
        }
    }

    cin >> q;
    while (q--)
    {
        int d0, h0, w0, dn, hn, wn;
        cin >> d0 >> h0 >> w0 >> dn >> hn >> wn;

        cout << V[hn][wn][dn] - (V[h0 - 1][wn][dn] + V[hn][w0 - 1][dn] + V[hn][wn][d0 - 1]) + (V[h0 - 1][w0 - 1][dn] + V[hn][w0 - 1][d0 - 1] + V[h0 - 1][wn][d0 - 1]) - (V[h0 - 1][w0 - 1][d0 - 1]) << "\n";
    }

    return 0;
}