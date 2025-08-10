#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int score;

    cin >> score;

    if(score >= 85)
        cout << "A";
    else if(score >= 80)
        cout << "B+";
    else if(score >= 75)
        cout << "B";
    else if(score >= 70)
        cout << "C+";
    else if(score >= 65)
        cout << "C";
    else if(score >= 60)
        cout << "D+";
    else if(score >= 50)
        cout << "D";
    else
        cout << "F";

    return 0;
}