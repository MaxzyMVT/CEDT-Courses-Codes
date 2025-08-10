#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string in;

    cin >> n;
    getline(cin>>ws,in);

    for(auto x : in)
    {
        if(isalpha(x))
        {
            if(x>'Z')
                cout << char(((x-'a')+26-n)%26 + 'a');
            else
                cout << char(((x-'A')+26-n)%26 + 'A');
        }
        else
            cout << x;
    }





    return 0;
}