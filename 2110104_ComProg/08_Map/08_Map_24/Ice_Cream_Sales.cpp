#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    map<string, double> prices; // type, price
    map<string, double> sales;  // type, price
    string type;
    double price;

    int n;
    cin >> n;
    while (n--)
    {
        cin >> type >> price;
        prices[type] = price;
    }

    double sum = 0, cnt, Mx = 0;
    cin >> n;
    while (n--)
    {
        cin >> type >> cnt;
        if (prices.find(type) != prices.end())
        {
            price = prices[type] * cnt;
            sales[type] += price;
            sum += price;
            Mx = max(Mx, sales[type]);
        }
    }

    if (sum > 0)
    {
        cout << "Total ice cream sales: " << sum << "\n";
        cout << "Top sales: ";
        for (auto [type, price] : sales)
        {
            if (price == Mx)
                cout << type << " ";
        }
    }
    else
        cout << "No ice cream sales";

    return 0;
}