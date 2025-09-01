#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    string names[10] = {"Robert", "William", "James", "John", "Margaret", "Edward", "Sarah", "Andrew", "Anthony", "Deborah"};
    string nicknames[10] = {"Dick", "Bill", "Jim", "Jack", "Peggy", "Ed", "Sally", "Andy", "Tony", "Debbie"};

    cin >> t;
    while (t--)
    {
        bool name_found = false;

        string in;
        cin >> in;

        for (int i = 0; i < 10; i++)
        {
            if (in == names[i])
                cout << nicknames[i] << "\n", name_found = true;
            else if (in == nicknames[i])
                cout << names[i] << "\n", name_found = true;
        }
        if (!name_found)
            cout << "Not found\n";
    }

    return 0;
}