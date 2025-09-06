#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> num = {"soon", "neung", "song", "sam", "si", "ha", "hok", "chet", "paet", "kao"};
    vector<string> special = {"sip", "roi", "phan", "muen", "saen", "lan"};
    vector<int> mul = {10, 100, 1000, 10000, 100000, 1000000};

    string in, word;
    getline(cin >> ws, in);

    while (in != "q")
    {
        int ans = 0, now = 1;
        in += " ";

        size_t FIND = 0;
        bool EndSpecial = false;
        while ((FIND = in.find(' ')) != string::npos)
        {
            word = in.substr(0, FIND);
            in.erase(0, FIND + 1);

            auto itr = find(special.begin(), special.end(), word);
            if (word == "et")
                ans += 1;
            else if (word == "yi")
                now = 2;
            else if (itr != special.end())
            {
                int pos = itr - special.begin();
                now *= mul[pos];
                ans += now;
                now = 1;
                EndSpecial = true;
            }
            else
            {
                itr = find(num.begin(), num.end(), word);
                now = itr - num.begin();
                EndSpecial = false;
            }
        }

        if (!EndSpecial)
            ans += now;

        cout << ans << "\n";

        getline(cin >> ws, in);
    }

    return 0;
}