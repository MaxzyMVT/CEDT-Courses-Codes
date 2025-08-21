#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    int A[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    double ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        double ans = 0;
        for (int j = n - i - 1; j >= 0; j--)
        {
            ans += A[j];
            ans = 1.0 / ans;
        }

        ans = 1.0 / ans;
        cout << setprecision(10) << ans << "\n";
    }

    return 0;
}