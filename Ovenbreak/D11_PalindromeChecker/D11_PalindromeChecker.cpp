#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b;
    string in;
    cin >> in >> n;

    while(n--)
    {
        cin >> a >> b;

        bool isPalindrome = true;
        for(int i=a;i<=b;i++)
        {
            if(in[i]!=in[b+a-i])
            {
                isPalindrome = false;
                break;  
            } 
        }
        cout << in.substr(a,b-a+1) << ": " << (isPalindrome ? "Yes" : "No") << "\n";
    }




    return 0;
}