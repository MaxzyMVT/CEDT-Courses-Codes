#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string hr, min;
    int h,m;
    char now;

    cin >> hr >> min;
    h = stoi(hr);
    m = stoi(min);

    if(h>=12)
        hr = string(2-to_string(h-12).size(),'0') + to_string(h-12);

    for(int i=1;i<=5;i++)
    {
        for(int k=1;k<=4;k++, cout << " ")
        {
            if(k>=3) 
                now = min[(k-1)%2];
            else
                now = hr[(k-1)%2];

            if(i==1)
            {
                if(now=='1') cout << "  #";
                else if(now=='4') cout << "# #";
                else cout << "###";               
            }
            else if(i==2)
            {
                if(now=='0'||now=='4'||now=='8'||now=='9') cout << "# #";
                else if(now=='5'||now=='6') cout << "#  ";
                else cout << "  #";
            }                
            else if(i==3)
            {
                if(now=='1'||now=='7') cout << "  #";
                else if(now=='0') cout << "# #";
                else cout << "###";
            }                
            else if(i==4)
            {
                if(now=='0'||now=='8'||now=='6') cout << "# #";
                else if(now=='0'||now=='2') cout << "#  ";
                else cout << "  #";
            }                
            else
            {
                if(now=='1'||now=='4'||now=='7') cout << "  #";
                else cout << "###";
            }
             

            if(k==2) 
                if(i==2||i==4) cout << " :";
                else cout << "  ";
        }

        if(i<=3)
        {
            if(i==1 || i==3) cout << "  ### ";
            else cout << "  # # ";
        }
        else if(h>=12)
            cout << "  #   ";
        else
            cout << "  # # ";

        if(i==2)
            cout << "###\n";
        else
            cout << "# #\n";
    }


    return 0;
}

