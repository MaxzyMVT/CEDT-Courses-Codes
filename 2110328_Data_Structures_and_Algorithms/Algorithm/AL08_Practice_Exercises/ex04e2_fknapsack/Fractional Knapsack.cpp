#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double w, a;
    cin >> w >> n;

    vector<tuple<double, double, double>> V(n);
    vector<double> val(n);

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> a, V[i] = {val[i] / a, val[i], a};

    sort(V.begin(), V.end(), greater<tuple<double, double, double>>());

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto [ratio, vi, wi] = V[i];

        if (w > wi)
            w -= wi, sum += vi;
        else
        {
            sum += w / wi * vi;
            break;
        }
    }
    cout << fixed << setprecision(4) << sum;

    return 0;
}
