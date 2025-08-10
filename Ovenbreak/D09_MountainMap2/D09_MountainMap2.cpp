#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Mx = 0;
    

    cin >> n;

    vector<int> V(n+1);


    for(int i=1;i<=n;i++)
        cin >> V[i], Mx = max(V[i],Mx);


    for(int i=Mx;i>=1;i--)
    {
        for(int k=1;k<=n;k++)
        {
            if(i==1) 
                cout << "_";
            else
                cout << " ";

            for(int j=1;j<=V[k];j++)
            {
                if(i==j)
                    cout << "/";
                else
                    cout << " ";
            }

            for(int j=V[k];j>=1;j--)
            {
                if(i==j)
                    cout << "\\";
                else
                    cout << " ";
            }

        }

        if(i==1)
            cout << "_";
        else
            cout << "\n";
    }





    return 0;
}