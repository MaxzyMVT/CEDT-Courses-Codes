#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string needle;
    string haystack;
    int cnt = 0;

    cin >> needle;
    cin.ignore();
    getline(cin >> ws, haystack);

    size_t pos = haystack.find(needle);
    while (pos != string::npos)
    {
        if ((pos == 0 || !isalpha(haystack[pos - 1])) && (pos + needle.size() == haystack.size() || !isalpha(haystack[pos + needle.size()])))
            cnt++;
        pos = haystack.find(needle, pos + 1);
    }

    cout << cnt;

    return 0;
}