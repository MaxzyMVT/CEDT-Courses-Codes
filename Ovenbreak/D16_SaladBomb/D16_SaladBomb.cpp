#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,sum = 0;
    cin >> n >> m;

    vector<int> C(n+1);
    for(int i=1;i<=n;i++)
        cin >> C[i];

    sort(C.begin(),C.end(),greater<int>());

    for(int x : C)
    {
        if(m) sum++, m--;
        else sum+=x;
    }

    cout << sum;


    return 0;
}