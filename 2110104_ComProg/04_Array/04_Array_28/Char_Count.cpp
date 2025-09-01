#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;
    int char_cnt[26] = {};
    getline(cin >> ws, in);

    for (auto x : in)
    {
        if (isalpha(x))
            char_cnt[toupper(x) - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (char_cnt[i])
            cout << char(i + 'a') << " -> " << char_cnt[i] << "\n";
    }

    return 0;
}