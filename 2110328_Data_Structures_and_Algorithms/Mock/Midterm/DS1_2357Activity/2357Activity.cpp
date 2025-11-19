#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, set<string>> PList;
    set<string> names;

    int n;
    cin >> n;

    stack<tuple<string, string, string, bool>> ST;
    bool isSucceed = false;
    while (n--)
    {
        string in, e, name;
        cin >> in;
        if (in == "ADDEVENT")
        {
            cin >> e;
            if (PList.find(e) == PList.end())
            {
                PList[e] = {};
            }
        }
        else if (in == "REGISTER")
        {
            cin >> e >> name;

            if (names.count(name) == 0)
            {
                names.insert(name);
                PList[e].insert(name);
                isSucceed = true;
            }
            else
                isSucceed = false;
            ST.push({in, e, name, isSucceed});
        }
        else if (in == "CANCEL")
        {
            cin >> e >> name;

            if (PList.find(e) != PList.end() && PList[e].count(name) != 0)
            {
                names.erase(name);
                PList[e].erase(name);
                isSucceed = true;
            }
            else
                isSucceed = false;
            ST.push({in, e, name, isSucceed});
        }
        else if (in == "SHOW")
        {
            cin >> e;
            for (string name : PList[e])
                cout << name << " ";
            cout << "\n";
        }
        else if (in == "UNDO" && !ST.empty())
        {
            auto [lastCom, e, name, isS] = ST.top();
            ST.pop();
            if (!isS)
                continue;
            if (lastCom == "CANCEL")
            {
                names.insert(name);
                PList[e].insert(name);
            }
            else if (lastCom == "REGISTER")
            {
                names.erase(name);
                PList[e].erase(name);
            }
        }
    }

    return 0;
}

/*
26
ADDEVENT Phonesiam
CANCEL Metro Wan
SHOW Coding
CANCEL Coding Phone
REGISTER IOT Wan
SHOW Camp
UNDO
CANCEL Phonesiam Prame
CANCEL Popsiam Phone
SHOW Camp
CANCEL Metro Euro
REGISTER Metro B
REGISTER Coding Phone
UNDO
SHOW Metro
REGISTER Boardgame Phone
CANCEL ICT Prame
CANCEL Camp B
SHOW Metro
UNDO
REGISTER Camp Knight
SHOW IOT
UNDO
SHOW Camp
SHOW Metro
UNDO
*/