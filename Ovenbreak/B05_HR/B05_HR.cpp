#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string ID1, ID2;
    int atk1, atk2, def1, def2, spd1, spd2, all1, all2;

    cin >> ID1 >> ID2;
    cin >> atk1 >> def1 >> spd1;
    cin >> atk2 >> def2 >> spd2;

    all1 = atk1 + def1 + spd1;
    all2 = atk2 + def2 + spd2; 


    if(all1 == all2 && atk1 == atk2 && spd1 == spd2)
    {
        if(ID1[2] == '3' && ID2[2] == '3')
        {
            if(ID1.substr(8,2) == "21" && ID2.substr(8,2) == "21")
            {
                if(ID1.substr(0,2) < ID2.substr(0,2))
                    cout << "Win: " << ID1;
                else if(ID1.substr(0,2) > ID2.substr(0,2))
                    cout << "Win: " << ID2;
                else
                    cout << "No one.";
            }
            else if(ID1.substr(8,2) == "21")
                cout << "Win: " << ID1;
            else\
                cout << "Win: " << ID2;
        }
        else if(ID1[2] == '3')
            cout << "Win: " << ID1;
        else
            cout << "Win: " << ID2;
    }
    else if(all1 > all2 || all1 == all2 && (atk1 > atk2 || atk1 == atk2 && spd1 > spd2))
        cout << "Win: " << ID1;
    else
        cout << "Win: " << ID2;

    
    return 0;
}