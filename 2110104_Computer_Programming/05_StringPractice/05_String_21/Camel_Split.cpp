#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;
    cin >> in;

    int n = in.size();
    int prev_pos = 0;
    bool isNum = isdigit(in[0]);

    for (int i = 1; i < n; i++)
    {
        int x = in[i];
        if (isupper(x))
        {
            if (isNum)
                isNum = false;
            cout << in.substr(prev_pos, i - prev_pos) << ", ";
            prev_pos = i;
        }
        else if (isNum ^ isdigit(x))
        {
            isNum ^= 1;
            cout << in.substr(prev_pos, i - prev_pos) << ", ";
            prev_pos = i;
        }
    }

    cout << in.substr(prev_pos);

    return 0;
}