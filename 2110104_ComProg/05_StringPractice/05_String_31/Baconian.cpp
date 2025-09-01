#include <iostream>
#include <string>

using namespace std;

string patterns[] = {
    "UUUU",
    "UUUL",
    "UULU",
    "UULL",
    "ULUU",
    "ULUL",
    "ULLU",
    "ULLL",
    "LUUU",
    "LUUL",
    "LULU",
    "LULL",
};

char chars[] = "0123456789-,";

string encode(string &in, string &decoy)
{
    string pattern = "";
    string ans = "";

    for (auto x : in)
    {
        int pos = 0;
        while (chars[pos] != x)
            pos++;
        pattern += patterns[pos];
    }

    int d = decoy.size();
    int n = pattern.size();

    for (int i = 0, j = 0; i < n; i++)
    {
        char x = decoy[j];

        while (!isalpha(x))
        {
            ans += x;
            j = (j + 1) % d;
            x = decoy[j];
        }

        if (pattern[i] == 'U')
            ans += toupper(x);
        else
            ans += tolower(x);

        j = (j + 1) % d;
    }

    return ans;
}

string decode(string &in)
{
    string pattern = "";
    string ans = "";
    for (auto x : in)
    {
        if (isalpha(x))
        {
            if (isupper(x))
                pattern += "U";
            else
                pattern += "L";
        }
        if (pattern.size() == 4)
        {
            int pos = 0;
            while (patterns[pos] != pattern)
                pos++;
            ans += chars[pos];
            pattern = "";
        }
    }

    return ans;
}

int main()
{
    string in, decoy;
    char com;

    getline(cin, decoy);

    while (cin >> com)
    {
        getline(cin >> ws, in);
        if (com == 'E')
            cout << encode(in, decoy) << "\n";
        else if (com == 'D')
            cout << decode(in) << "\n";
    }

    return 0;
}