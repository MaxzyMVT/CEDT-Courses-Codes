#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h;
    char c;

    cin >> h >> c;

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=h*2;j++)
        {
            if(j==h-i+1)
                cout << "/";
            else if(j==h+i)
                cout << "\\";
            else if(j<h-i+1 || j>h+i)
                cout << " ";
            else
                cout << c;
        } 
        cout << "\n";
    }



    return 0;
}