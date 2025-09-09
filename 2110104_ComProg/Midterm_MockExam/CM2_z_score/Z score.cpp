#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, z, avg, SD, sum = 0, sum_sq = 0;
    int cnt = 0, a;

    cin >> z >> a;
    while (a != -1)
    {
        cnt++;
        sum += a;
        sum_sq += a * a;
        cin >> a;
    }

    avg = sum / cnt;

    SD = sqrt(sum_sq / cnt - (avg * avg));

    x = (z * SD) + avg;

    cout << fixed << setprecision(5) << x << "\n";

    return 0;
}