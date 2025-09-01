#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in, out;
    while (getline(cin, in))
    {
        out = "";
        int n = in.size();
        int st_pos = 0, en_pos = n - 1;
        bool isOpen = false;

        for (int i = 0; i <= n; i++)
        {
            char x = in[i];
            bool isSpecial = x == in.back();
            if (!isOpen && isSpecial)
            {
                isOpen = true;
                st_pos = i;
            }
            else if (isSpecial)
            {
                isOpen = false;
                en_pos = i;
                out += in.substr(st_pos + 1, en_pos - st_pos - 1);
            }
        }

        cout << out << "\n";
    }

    return 0;
}