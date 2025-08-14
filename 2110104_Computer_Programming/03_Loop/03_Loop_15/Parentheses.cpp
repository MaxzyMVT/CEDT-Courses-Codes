#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string in;

    getline(cin, in, '\n');

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == '[')
            in[i] = '(';
        else if (in[i] == ']')
            in[i] = ')';
        else if (in[i] == '(')
            in[i] = '[';
        else if (in[i] == ')')
            in[i] = ']';
    }

    cout << in;

    return 0;
}