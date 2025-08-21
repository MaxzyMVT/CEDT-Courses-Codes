#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int n;
    string cards[100], in;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> cards[i];

    getline(cin >> ws, in);

    for (char x : in)
    {
        if (x == 'C')
        {
            for (int i = 0; i < n / 2; i++)
                swap(cards[i], cards[i + n / 2]);
        }
        else if (x == 'S')
        {
            string new_cards[100];
            for (int i = 0; i < n / 2; i++)
            {
                new_cards[i * 2] = cards[i];
                new_cards[i * 2 + 1] = cards[i + n / 2];
            }

            for (int i = 0; i < n; i++)
                cards[i] = new_cards[i];
        }
    }

    for (string card : cards)
        cout << card << " ";

    return 0;
}