#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string line, char delimiter)
{
    line += delimiter;
    int n = line.size(), prev_pos = 0;
    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        if (line[i] == delimiter)
        {
            string substring = line.substr(prev_pos, i - prev_pos);

            if (!substring.empty())
                ans.push_back(substring);

            prev_pos = i + 1;
        }
    }

    return ans;
}

int main()
{
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0]))
    {
        cout << '(' << e << ')';
    }
}