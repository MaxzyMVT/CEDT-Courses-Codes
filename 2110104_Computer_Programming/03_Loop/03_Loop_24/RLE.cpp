#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string in;
    char now;
    cin >> in;

    for (int i = 0; i < in.size(); i++)
    {
        int cnt = 1;
        char now = in[i];
        while (in[++i] == now)
        {
            cnt++;
        }
        i--;
        cout << in[i] << " " << cnt << " ";
    }

    return 0;
}