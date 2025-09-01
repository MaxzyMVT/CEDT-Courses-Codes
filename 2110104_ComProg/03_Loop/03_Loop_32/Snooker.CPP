#include <iostream>
#include <string>
using namespace std;

int main()
{
    string in;

    int n;
    cin >> n;

    cin.ignore();

    while (n--)
    {
        int cnt = 0;
        int pos = 0;
        int seq = 1;
        getline(cin, in);

        bool isValid = true;

        for (int i = 0; i < in.size(); i += 2)
        {
            if (in[i] == 'R')
                cnt += 1;
            else if (in[i] == 'Y')
                cnt += 2;
            else if (in[i] == 'G')
                cnt += 3;
            else if (in[i] == 'N')
                cnt += 4;
            else if (in[i] == 'B')
                cnt += 5;
            else if (in[i] == 'P')
                cnt += 6;
            else if (in[i] == 'K')
                cnt += 7;

            if (i == 0 && in[i] != 'R' || seq > 6)
            {
                isValid = false;
                break;
            }
            else if (in[i] != 'R' || seq > 1)
            {
                if (in[i - 2] == 'R')
                    continue;
                if (seq == 1 && in[i] == 'Y' ||
                    seq == 2 && in[i] == 'G' ||
                    seq == 3 && in[i] == 'N' ||
                    seq == 4 && in[i] == 'B' ||
                    seq == 5 && in[i] == 'P' ||
                    seq == 6 && in[i] == 'K')
                {
                    seq++;
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if (i != 0 && in[i] == 'R')
            {
                if (in[i - 2] == 'R')
                {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid)
            cout << cnt << "\n";
        else
            cout << "WRONG_INPUT\n";
    }

    return 0;
}