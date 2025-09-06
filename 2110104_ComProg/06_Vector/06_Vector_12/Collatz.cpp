#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> seq;

    while (n != 1)
    {
        seq.push_back(n);
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
    }

    for (auto beg = max(seq.end() - 14, seq.begin()), end = seq.end(); beg < end; beg++)
    {
        cout << *beg << "->";
    }

    cout << 1;

    return 0;
}