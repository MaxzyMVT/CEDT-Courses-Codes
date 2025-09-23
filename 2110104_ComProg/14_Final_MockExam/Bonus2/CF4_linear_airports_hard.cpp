#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int checkGate(int gate, string &Gates)
{
    int fwd = gate, bwd = gate;
    int n = Gates.size();
    while (fwd >= 0 || bwd <= n - 1)
    {
        fwd = max(0, fwd);
        bwd = min(n - 1, bwd);
        if (Gates[fwd] == '0')
            return fwd;
        if (Gates[bwd] == '0')
            return bwd;
        fwd--;
        bwd++;
    }
    return n;
}

pair<string, int> findHead(string AP, int relativeIDX, map<string, string> &Head, map<string, int> &HeadShift)
{
    if (Head[AP] == AP)
        return {AP, relativeIDX};
    auto [headAP, headIDX] = findHead(Head[AP], HeadShift[AP], Head, HeadShift);
    Head[AP] = headAP;
    HeadShift[AP] = headIDX;
    return {headAP, headIDX + relativeIDX};
}

void mergeAP(string AP1, string AP2, map<string, string> &Head, map<string, int> &HeadShift, map<string, string> &Gates)
{
    auto [u, idxU] = findHead(AP1, 0, Head, HeadShift);
    auto [v, idxV] = findHead(AP2, 0, Head, HeadShift);
    Head[v] = u;
    HeadShift[v] = Gates[u].size();
    Gates[u] += Gates[v];
}

int main()
{
    int A, F, cnt = 0;
    map<string, string> Gates;
    map<string, int> IDX;
    set<pair<int, string>> headAPs;
    map<string, string> Head;
    map<string, int> HeadShift;

    cin >> A >> F;

    while (A--)
    {
        string name, gates;
        int id;
        cin >> name >> id >> gates;
        Gates[name] = gates;
        IDX[name] = id;
        headAPs.insert({id, name});
        Head[name] = name;
        HeadShift[name] = 0;
    }

    for (int f = 0; f < F; f++)
    {
        string in, in2;
        cin >> in;
        if (in == "MERGE")
        {
            // MERGE K
            f--;
            int k, now;
            vector<string> merge;
            cin >> k;

            set<pair<int, string>> newHeadAPs;
            headAPs.insert({100, "~limiter"});
            for (auto &[idx, AP] : headAPs)
            {
                if (merge.empty())
                {
                    now = idx;
                    merge.push_back(AP);
                }
                else if (idx - now <= k)
                {
                    merge.push_back(AP);
                }
                else
                {
                    sort(merge.begin(), merge.end());
                    string headAP = merge.front();
                    newHeadAPs.insert({IDX[headAP], headAP});

                    // Sub APs Iterate & Gate Indexing
                    for (int i = 1; i < merge.size(); i++)
                    {
                        string subAP = merge[i];
                        mergeAP(headAP, subAP, Head, HeadShift, Gates);
                    }

                    now = idx;
                    merge.clear();
                    merge.push_back(AP);
                }
            }
            headAPs = newHeadAPs;
            continue;
        }

        cin >> in2;
        auto pos1 = in.find('[');
        auto pos2 = in2.find('[');

        // Input airport names
        string name1 = in.substr(0, pos1);
        string name2 = in2.substr(0, pos2);

        // Head relative gates
        int g1 = stoi(in.substr(pos1 + 1));
        int g2 = stoi(in2.substr(pos2 + 1));

        // Change to head airport names
        auto [AP1, gate1] = findHead(name1, g1, Head, HeadShift);
        auto [AP2, gate2] = findHead(name2, g2, Head, HeadShift);

        Gates[AP1][gate1] = '0';

        int validGate = checkGate(gate2, Gates[AP2]);
        if (validGate == Gates[AP2].size())
        {
            // CANCLE
            Gates[AP1][gate1] = '1';
            cout << f << " CANCEL\n";
        }
        else if (validGate != gate2)
        {
            // SHIFT
            string out = "SHIFT";
            if (AP1 == AP2)
                out = "ROUND_SHIFT";
            cout << f << " " << out << " " << AP2 << "[" << validGate << "]\n";
            Gates[AP2][validGate] = '1';
        }
        else
        {
            // NO CHANGE in flight f or ROUND
            cnt++;
            Gates[AP2][gate2] = '1';
            if (AP1 == AP2)
            {
                cout << f << " ROUND " << AP2 << "[" << gate2 << "]\n";
                cnt--;
            }
        }
    }

    if (F == cnt)
        cout << "NO CHANGE\n";

    return 0;
}