#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string in;

    while (cin >> in)
    {
        bool upper = 0, lower = 0, num = 0, spc = 0;
        for (auto x : in)
        {
            if (isupper(x))
                upper = 1;
            else if (islower(x))
                lower = 1;
            else if (isdigit(x))
                num = 1;
            else
                spc = 1;
        }

        if (in.size() >= 12 && upper && lower && num && spc)
            cout << ">> strong\n";
        else if (in.size() >= 8 && upper && lower && num)
            cout << ">> weak\n";
        else
            cout << ">> invalid\n";
    }

    return 0;
}