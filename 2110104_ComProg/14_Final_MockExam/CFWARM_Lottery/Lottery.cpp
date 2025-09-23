#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> lotto_count;
    char com;
    string max_lotto;
    int Mx = 0;

    cin >> com;
    while (com != 'E')
    {
        string lotto;
        if (com == 'K')
        {
            cin >> lotto;
            lotto_count[lotto]++;
            if (Mx < lotto_count[lotto])
            {
                Mx = lotto_count[lotto];
                max_lotto = lotto;
            }
        }
        else if (com == 'P')
        {
            cin >> lotto;
            if (lotto_count.find(lotto) != lotto_count.end())
                cout << lotto_count[lotto] << "\n";
            else
                cout << "0\n";
        }
        else if (com == 'H')
        {
            cout << max_lotto << "\n";
        }
        else if (com == 'N')
        {
            cout << lotto_count.size() << "\n";
        }

        cin >> com;
    }

    return 0;
}