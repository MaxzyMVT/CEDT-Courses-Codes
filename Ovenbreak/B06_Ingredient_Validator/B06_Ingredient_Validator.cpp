#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string season, moon, ing;

    cin >> season >> moon >> ing;

    if(season == "spring" || season == "summer")
    {
        if(moon == "full")
        {
            if(ing == "honey" || ing == "milk")
                cout << "Ingredient accepted!";
            else
                cout << "Ingredient rejected!";
        }
        else if(moon == "new" && ing != "chocolate")
            cout << "Ingredient rejected!";
        else
            cout << "Ingredient accepted!";
    }
    else
    {
        if(season == "autumn" || season == "winter")
        {
            if(moon == "waning" || moon == "new")
            {
                if(ing == "chocolate" || ing == "milk")
                    cout << "Ingredient accepted!";
                else
                    cout << "Ingredient rejected!";
            }
            else
                cout << "Ingredient accepted!";
        }
        else
            cout << "Ingredient rejected!";

    }

    

    return 0;
}