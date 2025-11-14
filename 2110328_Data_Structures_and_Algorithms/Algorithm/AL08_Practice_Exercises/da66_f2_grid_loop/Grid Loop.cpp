#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define edge tuple<int, int, int, int>

void setDir(int now, bool &inU, bool &inD, bool &inL, bool &inR)
{
    inU = false, inD = false, inL = false, inR = false;
    if (now == 1)
        inL = true, inR = true;
    else if (now == 2)
        inU = true, inD = true;
    else if (now == 3)
        inU = true, inR = true;
    else if (now == 4)
        inD = true, inR = true;
    else if (now == 5)
        inD = true, inL = true;
    else if (now == 6)
        inU = true, inL = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n, vector<int>(m));
    vector<vector<int>> walk(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> G[i][j];

    int cnt = 0, Mx = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (walk[i][j] != -1)
                continue;

            queue<edge> q;

            q.push({1, i, j, 0});
            while (q.size())
            {
                auto [w, r, c, dir] = q.front();
                q.pop();

                if (r < 0 || c < 0 || r >= n || c >= m)
                    continue;

                if (walk[r][c] == cnt)
                {
                    cnt++;
                    Mx = max(Mx, (w - 1) * 2);
                    break;
                }
                if (walk[r][c] != -1)
                    continue;
                walk[r][c] = cnt;

                int now = G[r][c];
                int U = r - 1 < 0 ? 0 : G[r - 1][c];
                int D = r + 1 >= n ? 0 : G[r + 1][c];
                int L = c - 1 < 0 ? 0 : G[r][c - 1];
                int R = c + 1 >= m ? 0 : G[r][c + 1];

                bool inU, inD, inL, inR, outU, outD, outL, outR, aux;

                setDir(now, inU, inD, inL, inR);
                setDir(U, aux, outU, aux, aux);
                setDir(D, outD, aux, aux, aux);
                setDir(L, aux, aux, aux, outL);
                setDir(R, aux, aux, outR, aux);

                if (inU && outU && dir != 2)
                    q.push({w + 1, r - 1, c, 1});
                if (inD && outD && dir != 1)
                    q.push({w + 1, r + 1, c, 2});
                if (inL && outL && dir != 4)
                    q.push({w + 1, r, c - 1, 3});
                if (inR && outR && dir != 3)
                    q.push({w + 1, r, c + 1, 4});
            }
        }

    cout << cnt << " " << Mx;

    return 0;
}