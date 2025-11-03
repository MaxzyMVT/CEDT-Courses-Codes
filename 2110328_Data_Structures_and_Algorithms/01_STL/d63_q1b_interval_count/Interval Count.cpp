#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, a;
    vector<int> numbers;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> a, numbers.push_back(a);

    sort(numbers.begin(), numbers.end());

    for (int j = 0; j < m; j++)
    {
        cin >> a;
        auto p = lower_bound(numbers.begin(), numbers.end(), a - k);
        auto q = upper_bound(numbers.begin(), numbers.end(), a + k);

        cout << q - p << " ";
    }

    return 0;
}