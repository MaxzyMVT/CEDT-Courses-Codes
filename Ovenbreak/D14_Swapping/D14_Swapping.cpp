#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,A[6];

    cin >> n;
    while(n--)
    {
        bool isSortable = true;
        bool isSwapped = false;


        for(int i=1;i<=5;i++)
            cin >> A[i];

        for(int i=2;i<=5;i++)
            if(!isSwapped && A[i-1] > A[i])
                swap(A[i-1],A[i]), isSwapped = true;

        for(int i=2;i<=5;i++)
            if(A[i-1] > A[i])
                isSortable = false;

        cout << (isSortable ? "Yes\n" : "No\n");
    }

    return 0;
}