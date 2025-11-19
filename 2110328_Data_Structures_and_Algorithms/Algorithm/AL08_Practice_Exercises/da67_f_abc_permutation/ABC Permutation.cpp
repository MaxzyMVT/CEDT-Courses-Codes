#include <iostream>
#include <vector>
using namespace std;

void perm(int pos, string &ans, vector<int> &alpha_cnt, vector<int> &alpha_lim, vector<string> &V)
{
    if (pos == ans.size())
    {
        V.push_back(ans);
        return;
    }

    string T = "ABC";
    for (int i = 0; i < 3; i++)
    {
        if (alpha_cnt[i] < alpha_lim[i])
        {
            alpha_cnt[i]++;
            ans[pos] = T[i];
            perm(pos + 1, ans, alpha_cnt, alpha_lim, V);
            alpha_cnt[i]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> alpha_cnt(3);
    vector<int> alpha_lim(3);
    int n, A, B, C;

    cin >> n >> alpha_lim[0] >> alpha_lim[1] >> alpha_lim[2];

    string ans(n, ' ');
    vector<string> V;

    perm(0, ans, alpha_cnt, alpha_lim, V);

    cout << V.size() << "\n";
    for (string s : V)
        cout << s << "\n";

    return 0;
}