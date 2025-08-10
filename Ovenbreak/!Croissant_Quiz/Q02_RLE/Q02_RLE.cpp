#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string in;
    cin >> in;


    if(isdigit(in[0]))
    {
        while(in.size())
        {
            int n = stoi(in);
            in.erase(0,to_string(n).size());
            char c = in[0];
            in.erase(0,1);

            for(int i=1;i<=n;i++)
                cout << c;            
        }
    }
    else
    { 
        int cnt = 0;
        char c,pc = in[0];
        in += "1";
        while(in.size())
        {
            c = in[0];
            in.erase(0,1);

            if(c!=pc)
                cout << cnt << pc, cnt = 0;
            pc = c;
            cnt++;
        }
    }


    return 0;
}