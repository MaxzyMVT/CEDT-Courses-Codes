#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int icnt = 0, spd = 1, n;
    char com1, com2, com3;
    string in;

    cin >> n;
    while(n--)
    {
        cin >> in;
        if(in=="oii")
        {
            cin >> com1;
            cin >> com2;
            cin >> com3;
            while(com1!='i'||com2!='i'||com3!='i')
            {
                for(int i=1;i<=spd;i++)
                    cout << com1 << " ";
                com1 = com2;
                com2 = com3;
                cin >> com3;
            }
        }
        else
        {
            icnt = 0;
            while(icnt<3)
            {
                cin >> com1;
                if(com1=='i') icnt++;
                else if(com1=='a') spd++;
                else spd = max(spd-1,1);
            }
        }
    }

    return 0;
}