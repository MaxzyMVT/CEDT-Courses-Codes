#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string in, final;
    char now;
    int k;
    cin >> in >> k;

    for (int i = 0; i < in.size(); i++)
    {
        int cnt = 1;
        char now = in[i];
        while (in[++i] == now)
        {
            cnt++;
        }
        i--;
        if (cnt < k)
        {
            final += in.substr(i - cnt + 1, cnt);
        }
    }

    cout << final;

    return 0;
}