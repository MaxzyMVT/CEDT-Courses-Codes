#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in1, in2;
    cin >> in1 >> in2;

    in1 = " " + in1;
    in2 = " " + in2;

    vector<vector<int>> V(in1.size(), vector<int>(in2.size()));

    for (int i = 1; i < in1.size(); i++)
    {
        for (int j = 1; j < in2.size(); j++)
        {
            if (in1[i] == in2[j])
                V[i][j] = V[i - 1][j - 1] + 1;
            else
                V[i][j] = max(V[i - 1][j], V[i][j - 1]);
        }
    }

    cout << V.back().back();

    return 0;
}
