#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    if(n==1)
    {
        double price, num;
        cin >> price >> num;
        cout << floor(price*num);
    }
    else if(n==2)
    {
        int p;
        cin >> p;
        if(p>=85)
            cout << "A";
        else if(p>=80)
            cout << "B+";        
        else if(p>=75)
            cout << "B";        
        else if(p>=70)
            cout << "C+";        
        else if(p>=65)
            cout << "C";      
        else if(p>=60)
            cout << "D+";      
        else if(p>=50)
            cout << "D";      
        else
            cout << "F";
    }
    else if(n==3)
    {
        int p;
        cin >> p;
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cout << "*";
            }
            if(i%3==0 || i%11==0) cout << " Ti amo";
            cout << "\n";
        } 
    }
    else if(n==4)
    {
        int m,p;
        cin >> m;

        vector<int> V(m+1);

        for(int i=1;i<=m;i++)
            cin >> V[i];

        cin >> p;

        int cnt = 0;

        for(int i=1;i<=m;i++)
        {
            if(V[i]==p) cnt++;  
        }
        cout << cnt;

    }

    return 0;
        
}