#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void permute(int pos, string &ans, map<char, int> &alpha, set<string> &perms)
{
    if (pos == ans.size())
    {
        perms.emplace(ans);
        return;
    }

    for (auto it = alpha.begin(); it != alpha.end(); it++)
    {
        auto [c, cnt] = *it;
        if (cnt <= 0)
            continue;
        it->second--;
        ans[pos] = c;
        permute(pos + 1, ans, alpha, perms);
        it->second++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    set<string> permutations;
    map<char, int> alpha;

    cin >> in;
    string ans(in);

    for (char c : in)
        alpha[c]++;

    permute(0, ans, alpha, permutations);

    cout << permutations.size() << "\n";
    for (string s : permutations)
        cout << s << "\n";

    return 0;
}