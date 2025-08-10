#include <bits/stdc++.h>
using namespace std;

#define ull long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n;
    string in,out;

    cin >> n;
    while(n--)
    {
        cin >> in >> out;

        if(abs((ull)(in.size())-(ull)(out.size())) > 1)
        {
            cout << "No\n";
            continue;
        }
        else if(in == out)
        {
            cout << "Yes\n";
            continue;
        }

        if(in.size()<out.size())
            swap(in,out);
       
        bool isAble1 = true, isAble3 = true;

        int j = 0;
        bool did = false;
        if(in.size()>out.size())
            for(int i=0;i<in.size();i++,j++)
            {
                if(!did && in[i]!=out[j])
                {
                    did = true;
                    j--;
                }
                else if(in[i]!=out[j])
                {
                    isAble1 = false;
                }
            }
        else 
            isAble1 = false;


        if(in.size()==out.size())
        {
            ull cnt = 0;
            for(ull i=0;i<in.size();i++)
                if(in[i]!=out[i])
                    cnt++;
            if(cnt>1)
                isAble3 = false;
        }
        else
            isAble3 = false;

        cout << (isAble1 || isAble3 ? "Yes\n" : "No\n");


    }

    return 0;
}