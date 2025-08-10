#include <bits/stdc++.h>
using namespace std;

#define ull long long

ull powULL(ull num, ull exp)
{
    if(exp==2) return num*num;
    if(exp==1) return num;
    if(exp==0) return 1;

    ull half = powULL(num,exp/2);
    ull ans = half*half;
    if(exp%2) ans*=num;

    return ans;
}

ull base10(string str, ull base)
{
    ull dec = 0;
    for(ull i=0;i<str.size();i++)
        dec += (str[i]-'0')*powULL(base,str.size()-i-1);
    
    return dec;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull ans,n,lenA,lenB,leadA,leadB;

    string A,B;

    cin >> n;
    for(ull t=1;t<=n;t++)
    {
        ans = 0;
        cin >> A >> B;
        lenA = A.size();
        lenB = B.size();
        leadA = A[0]-'0';
        leadB = B[0]-'0';

        bool conA = false;
        for(ull i=1;i<lenA;i++)
        {
            while(A[i]-'0'>=leadA)
            {
                if(i==0)
                {
                    if(A[i]-'0'>9) A="9"+string(lenA-1,'8'), ans--;
                    conA = true;
                    break;
                }
                A=A.substr(0,i)+string(lenA-i,'0');
                A[i-1]++;
                i--;
            }
            if(conA) break;
        }

        bool conB = false;
        for(ull i=1;i<lenB;i++)
        {
            if(conB)
                B[i] = leadB-1+'0';
            else if(leadB-1 < B[i]-'0')
                B[i] = leadB-1+'0', conB = true;
        }

        leadA = A[0]-'0';
        leadB = B[0]-'0';
        ull aa = stoull(A);
        ull bb = stoull(B);

        if(lenA==lenB && aa<=bb && leadA==leadB)
        {
            ull st = base10(A.substr(1),leadA);
            ull en = base10(B.substr(1),leadB);
            ans += en+1-st;
        }
        else if(aa<=bb)
        {
            ull st = base10(A.substr(1),leadA);
            ull en = base10(string(lenA-1,'0'+leadA-1),leadA);
            ans+=en+1-st;

            st = base10(string(lenB-1,'0'),leadB);
            en = base10(B.substr(1),leadB);
            ans+=en+1-st;
        }

        for(ull i=lenA; i<=lenB; i++)
        {
            ull st = 1, en = 9;
            if(i==lenA)
                st = A[0]-'0'+1;         
            if(i==lenB)
                en = B[0]-'0'-1;

            for(ull j=st;j<=en;j++)
                ans+=powULL(j,i-1);
        }

        cout << ans << "\n";

    } 


    return 0;
}

/*
10 | 1
20 21 | 2
30 31 32 | 3
40 41 42 43 | 4
.
.
9
45



100 | 1
200 201 210 211 | 4
300 301 302 310 311 312 320 321 322 | 9
16
.
.
81
258


21628005945912598 
150094635296999121
16677181699666569

3000
3001
3002
3010 * 010-base 3-> 3
3011
3012 
3020 
3021
3022
3100
3101 * 101-base 3-> 10
3102

between = 8 = 10-3+1??

15
301 3102
200 211
100 322
9889 10000
9888 10000
5644 6733
5355 6900
5355 9000
5355 945521
10 468431213543
7865654 95485743513332
11 20
15 20
12 15
10 19

300
4
14
1
2
216
241
1097
109248
5569949086
2644178696833
1
1
0
1
9221


*/