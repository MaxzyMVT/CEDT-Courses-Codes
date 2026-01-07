#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<double> prices;
    vector<pair<double, string>> sales;
    bool noSales = true;

    string in;

    cin >> in;
    while (in != "END")
    {
        sales.push_back({0, in});
        cin >> in;
        prices.push_back(stold(in));
        cin >> in;
    }

    while (cin >> in)
    {
        auto itr = sales.begin();
        while (itr != sales.end() && itr->second != in)
            itr++;

        if (itr == sales.end())
            continue;

        int pos = itr - sales.begin();
        sales[pos].first -= prices[pos];
        noSales = false;
    }

    sort(sales.begin(), sales.end());

    if (noSales)
        cout << "No Sales";
    else
    {
        int n = min((int)sales.size(), 3);
        for (int i = 0; i < n; i++)
            if (sales[i].first < 0)
                cout << sales[i].second << " " << -sales[i].first << "\n";
    }

    return 0;
}