#include <iostream>

using namespace std;

int main()
{
    string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tys[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string bigs[] = {"hundred", "thousand", "million", "billion", "trillion"};

    string in;
    cin >> in;

    if (in == "0")
    {
        cout << digits[0];
        return 0;
    }

    int n = in.size();
    bool skip = false;
    for (int i = 0; i < n; i++)
    {
        int x = in[i] - '0';
        int digit_pos = n - i;

        if (x == 0 && !skip)
            continue;

        if ((digit_pos + 1) % 3 == 0)
        {
            if (x == 1)
            {
                cout << teens[in[i + 1] - '0'] << " ";
                skip = true;
            }
            else
            {
                cout << tys[x] << " ";
                if (in[i + 1] == '0')
                    skip = true;
            }
        }
        else
        {
            if (!skip)
                cout << digits[x] << " ";
            else
                skip = false;

            if (digit_pos == 4)
                cout << bigs[1] << " ";
            else if (digit_pos == 7)
                cout << bigs[2] << " ";
            else if (digit_pos == 10)
                cout << bigs[3] << " ";
            else if (digit_pos == 13)
                cout << bigs[4] << " ";
            else if (digit_pos % 3 == 0)
                cout << bigs[0] << " ";
        }
    }

    return 0;
}