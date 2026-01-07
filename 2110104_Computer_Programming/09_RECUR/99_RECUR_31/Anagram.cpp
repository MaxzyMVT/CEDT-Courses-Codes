#include <iostream>
#include <set>
using namespace std;

set<string> makeAnagrams(const string &in)
{
    set<string> Anagrams;
    Anagrams.insert(in);

    int n = in.size();

    if (n <= 1)
        return Anagrams;

    for (int i = 0; i < n; i++)
    {
        string sub = in;
        sub.erase(sub.begin() + i);

        auto subAnagrams = makeAnagrams(sub);

        for (auto &subAnagram : subAnagrams)
            Anagrams.insert(in[i] + subAnagram);
    }

    return Anagrams;
}

int main()
{
    string in;
    cin >> in;

    auto Anagrams = makeAnagrams(in);
    for (auto &anagram : Anagrams)
        cout << anagram << " ";

    return 0;
}