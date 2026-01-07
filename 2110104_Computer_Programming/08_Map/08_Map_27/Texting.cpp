#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, char> CHAR; // Number Combination, Character
    unordered_map<char, string> NUMS; // Character, Number Combination

    char now = 'a';
    for (char num = '2'; num <= '9'; num++)
    {
        int n = (num == '7' || num == '9') ? 4 : 3;
        for (int len = 1; len <= n; len++)
        {
            string num_combi(len, num);
            CHAR[num_combi] = now;
            NUMS[now] = num_combi;
            now++;
        }
    }
    CHAR["0"] = ' ';
    NUMS[' '] = "0";

    string in;
    while (cin >> in)
    {
        cout << ">> ";
        if (in == "T2K")
        {
            getline(cin >> ws, in);
            for (char c : in)
            {
                if (isalpha(c) || c == ' ')
                    cout << NUMS[tolower(c)] << " ";
            }
        }
        else if (in == "K2T")
        {
            getline(cin >> ws, in);
            stringstream ss(in);

            while (ss >> in)
                cout << CHAR[in];
        }
        cout << endl;
    }

    return 0;
}