#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matMulMod(vector<vector<int>> A, vector<vector<int>> B, int MOD)
{
    vector<vector<int>> C(2, vector<int>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] % MOD + (A[i][k] % MOD * B[k][j] % MOD) % MOD) % MOD;
    return C;
}

vector<vector<int>> matPowMod(vector<vector<int>> &M, int n, int k)
{
    vector<vector<int>> IdentityM = {{1, 0}, {0, 1}};
    if (n == 0)
        return IdentityM;
    if (n == 1)
        return {
            {M[0][0] % k, M[0][1] % k},
            {M[1][0] % k, M[1][1] % k}};

    vector<vector<int>> ans = matPowMod(M, n / 2, k);
    ans = matMulMod(ans, ans, k);

    if (n % 2 == 1)
        return matMulMod(ans, M, k);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, a;
    vector<vector<int>> M(2, vector<int>(2));

    cin >> n >> k;
    cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1];

    M = matPowMod(M, n, k);

    cout << M[0][0] << " " << M[0][1] << " " << M[1][0] << " " << M[1][1];

    return 0;
}