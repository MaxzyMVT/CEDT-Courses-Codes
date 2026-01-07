#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<int> Union, Intersection, Differnce;
    string in;
    bool first_itr = true;

    while (getline(cin >> ws, in))
    {
        set<int> Tmp;

        in += ' ';
        size_t fnd;
        int pos = 0, len = 0;
        while ((fnd = in.find(' ', pos)) != string::npos)
        {
            len = fnd - pos;
            int num = stoi(in.substr(pos, len));
            pos = fnd + 1;

            Union.insert(num);
            if (first_itr)
                Tmp.insert(num);
            else if (Intersection.find(num) != Intersection.end())
                Tmp.insert(num);
            Differnce.erase(num);
        }

        Intersection = Tmp;

        if (first_itr)
            Differnce = Intersection;

        first_itr = false;
    }

    cout << "U: ";
    if (Union.empty())
        cout << "empty set";
    for (int e : Union)
        cout << e << " ";

    cout << "\nI: ";
    if (Intersection.empty())
        cout << "empty set";
    for (int e : Intersection)
        cout << e << " ";

    cout << "\nD: ";
    if (Differnce.empty())
        cout << "empty set";
    for (int e : Differnce)
        cout << e << " ";

    return 0;
}