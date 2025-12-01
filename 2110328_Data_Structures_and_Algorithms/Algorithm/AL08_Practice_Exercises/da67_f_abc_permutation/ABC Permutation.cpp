#include <iostream>
#include <vector>
#include <string>
using namespace std;

void gen_ABC_permutation(int pos, string &ans, vector<int> &cnt, vector<int> &limit, vector<string> &permutations)
{
    if (pos >= ans.size())
    {
        permutations.push_back(ans);
        return;
    }

    string alpha = "ABC";
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] < limit[i])
        {
            cnt[i]++;
            ans[pos] = alpha[i];
            gen_ABC_permutation(pos + 1, ans, cnt, limit, permutations);
            cnt[i]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> limit(3), cnt(3);
    vector<string> perms;

    cin >> limit[0] >> limit[1] >> limit[2];

    string ans(n, 'A');
    gen_ABC_permutation(0, ans, cnt, limit, perms);

    cout << perms.size() << "\n";
    for (string ans : perms)
        cout << ans << "\n";

    return 0;
}