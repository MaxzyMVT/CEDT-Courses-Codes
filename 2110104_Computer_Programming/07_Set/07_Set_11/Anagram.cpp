#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string in;
    multiset<char> A, B;

    getline(cin >> ws, in);
    for (char c : in)
    {
        if (c == ' ')
            continue;
        A.insert(tolower(c));
    }

    getline(cin >> ws, in);
    for (char c : in)
    {
        if (c == ' ')
            continue;
        B.insert(tolower(c));
    }

    if (A == B)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}