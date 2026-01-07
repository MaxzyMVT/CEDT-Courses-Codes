#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    set<int> nums;
    vector<int> A;

    int n, a;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
        nums.insert(a);
    }

    for (int i = 0; i < n; i++)
    {
        cout << (nums.find(2 * A[i]) != nums.end()) << " ";
    }

    return 0;
}