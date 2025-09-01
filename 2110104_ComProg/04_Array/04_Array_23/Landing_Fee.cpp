#include <iostream>
#include <string>

using namespace std;

int main()
{
    string countries[100];
    int prices[100];
    int n, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string country_name;
        int price;
        cin >> country_name >> price;
        countries[i] = country_name;
        prices[i] = price;
    }

    string destination, prev = "fst";
    while (cin >> destination)
    {
        destination = destination.substr(destination.find('-') + 1);

        if (prev != destination && prev != "fst")
        {
            int pos = 0;
            while (destination != countries[pos])
            {
                pos++;
            }
            sum += prices[pos];
        }

        prev = destination;
    }

    cout << sum;

    return 0;
}