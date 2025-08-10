#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string in;
    cin >> in;

    int n = in.size();


    //upper half
    for(int i=1;i<=3;i++)
    {
        //left
        if(i==1)
        {
            cout << "  ###";
            for(int j=1;j<=n;j++)
            {
                if(j%2) cout << "^#^";
                else cout << "*#*";
            }
            cout << "###";
        }
        else if(i==2)
        {
            cout << " ###";
            for(int j=1;j<=n;j++)
            {
                if(j%2) cout << "#*#";
                else cout << "#^#";
            }
            cout << "### ";
        }
        else
        {
            cout << "###";
            for(int j=1;j<=n*3;j++)
            {
                cout << "-";
            }
            cout << "###  ";
        }

        cout << "|";

        //right
        cout << "|";
        if(i==1)
        {   
            cout << "###";
            for(int j=n;j>=1;j--)
            {
                if(j%2) cout << "^#^";
                else cout << "*#*";
            }
            cout << "###  ";
        }
        else if(i==2)
        {
            cout << " ###";
            for(int j=n;j>=1;j--)
            {
                if(j%2) cout << "#*#";
                else cout << "#^#";
            }
            cout << "### ";
        }
        else
        {
            cout << "  ###";
            for(int j=n*3;j>=1;j--)
            {
                cout << "-";
            }
            cout << "###";
        }

        cout << "\n";
    }

    //MID
    cout << "###";
    for(int j=1;j<=n;j++)
        cout << " ";
    cout << in;
    for(int j=1;j<=n;j++)
        cout << " ";     
    cout << "###  |";

    cout << "|  ###";
    for(int j=1;j<=n;j++)
        cout << " ";
    cout << in;
    for(int j=1;j<=n;j++)
        cout << " ";     
    cout << "###\n";



    //lower half
    for(int i=3;i>=1;i--)
    {
        //left
        if(i==1)
        {
            cout << "  ###";
            for(int j=1;j<=n;j++)
            {
                if(j%2) cout << "^#^";
                else cout << "*#*";
            }
            cout << "###";
        }
        else if(i==2)
        {
            cout << " ###";
            for(int j=1;j<=n;j++)
            {
                if(j%2) cout << "#*#";
                else cout << "#^#";
            }
            cout << "### ";
        }
        else
        {
            cout << "###";
            for(int j=1;j<=n*3;j++)
            {
                cout << "-";
            }
            cout << "###  ";
        }

        cout << "|";

        //right
        cout << "|";
        if(i==1)
        {   
            cout << "###";
            for(int j=n;j>=1;j--)
            {
                if(j%2) cout << "^#^";
                else cout << "*#*";
            }
            cout << "###  ";
        }
        else if(i==2)
        {
            cout << " ###";
            for(int j=n;j>=1;j--)
            {
                if(j%2) cout << "#*#";
                else cout << "#^#";
            }
            cout << "### ";
        }
        else
        {
            cout << "  ###";
            for(int j=n*3;j>=1;j--)
            {
                cout << "-";
            }
            cout << "###";
        }

        cout << "\n";
    }
    return 0;
}