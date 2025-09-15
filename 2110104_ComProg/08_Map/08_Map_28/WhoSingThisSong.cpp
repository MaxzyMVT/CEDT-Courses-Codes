#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string>> Singers; // Song name, List of singers

    int n, cnt = 1;
    string in;
    cin >> n;

    while (n--)
    {
        getline(cin >> ws, in);
        size_t delim_pos = in.find(',');

        string songName = in.substr(0, delim_pos);
        string singer = in.substr(delim_pos + 2);

        Singers[songName].push_back(singer);
    }

    getline(cin >> ws, in);
    in += ", ";

    size_t delim_pos = 0, prev_pos = 0;
    while ((delim_pos = in.find(',', prev_pos)) != string::npos)
    {
        string songName = in.substr(prev_pos, delim_pos - prev_pos);
        prev_pos = delim_pos + 2;

        cout << songName << " -> ";
        if (Singers[songName].empty())
            cout << "Not found";
        else
        {
            bool not_fst_itr = false;
            for (auto singer : Singers[songName])
            {
                if (not_fst_itr)
                    cout << ", ";
                cout << singer;
                not_fst_itr = true;
            }
        }
        cout << "\n";
    }

    return 0;
}