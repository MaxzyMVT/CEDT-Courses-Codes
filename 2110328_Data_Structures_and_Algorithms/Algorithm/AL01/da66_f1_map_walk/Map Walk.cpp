#include <iostream>
#include <vector>
using namespace std;

void walk(int r, int c, vector<vector<bool>> &V, string &path)
{
    if (r < 1 || c < 1 || r >= V.size() || c >= V[0].size() || V[r][c])
        return;
    if (r == V.size() - 1 && c == V[0].size() - 1)
    {
        cout << path << "\n";
        return;
    }

    V[r][c] = true;

    path += "A";
    walk(r, c + 1, V, path);

    path[path.size() - 1] = 'B';
    walk(r + 1, c, V, path);

    path[path.size() - 1] = 'C';
    walk(r - 1, c, V, path);

    V[r][c] = false;
    path.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, a;
    cin >> R >> C;

    vector<vector<bool>> V(R + 1, vector<bool>(C + 1));
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            cin >> a;
            V[i][j] = a;
        }

    string path = "";
    walk(1, 1, V, path);
    cout << "DONE";

    return 0;
}