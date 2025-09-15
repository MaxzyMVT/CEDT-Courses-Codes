#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<string, double> baht_per1;
    string currency, prev_currency;
    double value;

    int n;
    cin >> n;
    while (n--)
    {
        cin >> currency >> value;
        baht_per1[currency] = value;
    }

    baht_per1["THB"] = 1;
    prev_currency = currency = "THB";

    int val;

    cin >> val >> prev_currency;
    bool first_itr = true;
    while (cin >> currency || prev_currency != "")
    {
        if (!first_itr)
            cout << " -> ";
        cout << val << " " << prev_currency;

        val = int(val * baht_per1[prev_currency] / baht_per1[currency]);

        prev_currency = currency;
        currency = "";
        first_itr = false;
    }

    return 0;
}