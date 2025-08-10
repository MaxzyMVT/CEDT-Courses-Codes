#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int year;
    cin >> year;

    if(year <= 0)
        cout << "year cannot be negative";
    else if(year%4==0 && year%100 || year%400==0)
        cout << "leap year";
    else
        cout << "not leap year";

    return 0;
}