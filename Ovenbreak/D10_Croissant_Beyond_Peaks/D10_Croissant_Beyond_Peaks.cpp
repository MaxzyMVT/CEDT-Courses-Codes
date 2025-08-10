#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, st, en;
    char C[3][501];

    cin >> n;
    while(n--)
    {
        cin >> m;
        bool walkable = true;
        for(int i=1;i<=2;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> C[i][j];
                if(C[i][j]=='S') 
                    st = j;
                else if(C[i][j]=='T')
                    en = j;
            }  
        }

        int tmp = st;
        st = min(st,en);
        en = max(tmp,en);
        
        for(int j=st;j<=en;j++)
        {
            if(C[1][j]=='#')
            {
                if(j!=st && C[2][j-1] == '#') walkable = false;
                if(j!=en && C[2][j+1] == '#') walkable = false;
                if(C[2][j] == '#') walkable = false;
            }
        }

        if(walkable)
            cout << "Yes\n";
        else
            cout << "No\n";
    }




    return 0;
}