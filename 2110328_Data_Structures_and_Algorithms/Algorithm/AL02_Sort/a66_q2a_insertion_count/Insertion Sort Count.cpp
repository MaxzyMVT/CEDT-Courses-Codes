#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> data;

    int n, m, a;
    cin >> n >> m;
    while (n--)
        cin >> a, data.push_back(a);

    while (m--)
    {
        cin >> a;
        int greaterLeft = 0;

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == a)
                break;
            if (data[i] > a)
                greaterLeft++;
        }
        cout << greaterLeft << "\n";
    }

    return 0;
}