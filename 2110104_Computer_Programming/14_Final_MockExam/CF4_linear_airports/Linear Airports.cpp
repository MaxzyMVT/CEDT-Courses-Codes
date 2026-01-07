#include <iostream>
#include <map>
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

int main()
{
    int A, F, cnt = 0;
    map<string, string> Gates;

    cin >> A >> F;

    while (A--)
    {
        string name, gates;
        cin >> name >> gates;
        Gates[name] = gates;
    }

    for (int f = 0; f < F; f++)
    {
        string in, in2;
        cin >> in;
        if (in == "MERGE")
        {
            // MERGE
            f--;
            string X, Y;
            cin >> X >> Y;
            if (Y < X)
                swap(X, Y);
            Gates[X] += Gates[Y];
            Gates.erase(Y);
            continue;
        }

        cin >> in2;
        auto pos1 = in.find('[');
        auto pos2 = in2.find('[');

        int gate1 = stoi(in.substr(pos1 + 1));
        int gate2 = stoi(in2.substr(pos2 + 1));

        string AP1 = in.substr(0, pos1);
        string AP2 = in2.substr(0, pos2);

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
            cout << f << " SHIFT " << AP2 << "[" << validGate << "]\n";
            Gates[AP2][validGate] = '1';
        }
        else
        {
            // NO CHANGE in flight f
            cnt++;
            Gates[AP2][gate2] = '1';
        }
    }

    if (F == cnt)
        cout << "NO CHANGE\n";

    return 0;
}