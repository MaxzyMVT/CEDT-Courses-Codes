#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool num_found[10] = {};

    string in;
    getline(cin, in);

    for (auto x : in)
        if (isdigit(x))
            num_found[x - '0'] = true;

    bool isFirst = true;
    for (int i = 0; i < 10; i++)
        if (!num_found[i])
        {
            if (!isFirst)
                cout << ",";
            else
                isFirst = false;
            cout << i;
        }

    if (isFirst)
        cout << "None";

    return 0;
}