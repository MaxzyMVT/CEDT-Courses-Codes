#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double sum = 0;
    double n = 0, a;

    while (true)
    {
        cin >> a;
        if (a == -1 && n == 0)
        {
            cout << "No Data" << endl;
            return 0;
        }
        if (a == -1)
            break;
        n++;
        sum += a;
    }

    cout << round(sum / n * 100) / 100;

    return 0;
}