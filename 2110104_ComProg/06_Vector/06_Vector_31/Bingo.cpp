#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkBingo(const vector<vector<int>> &V, vector<bool> &cons)
{
    bool isBingo = true, Ans = false;

    // Check Horizontal
    for (int i = 0; i < 5; i++)
    {
        isBingo = true;
        for (int j = 0; j < 5; j++)
        {
            if (V[j][i] != -1)
            {
                isBingo = false;
                break;
            }
        }
        Ans |= cons[i] = isBingo;
    }

    // Check Vertical
    for (int j = 0; j < 5; j++)
    {
        isBingo = true;
        for (int i = 0; i < 5; i++)
        {
            if (V[j][i] != -1)
            {
                isBingo = false;
                break;
            }
        }
        Ans |= cons[j + 5] = isBingo;
    }

    // Check Upper-Left to Lower-Right
    isBingo = true;
    for (int i = 0; i < 5; i++)
    {
        if (V[i][i] != -1)
        {
            isBingo = false;
            break;
        }
    }
    Ans |= cons[10] = isBingo;

    // Check Lower-Left to Upper-Right
    isBingo = true;
    for (int i = 0; i < 5; i++)
    {
        if (V[i][4 - i] != -1)
        {
            isBingo = false;
            break;
        }
    }
    Ans |= cons[11] = isBingo;

    return Ans;
}

void printBingo(const vector<vector<int>> &V, const vector<bool> &cons, const string &name)
{
    // Print Horizontal
    for (int i = 0; i < 5; i++)
    {
        if (!cons[i])
            continue;
        for (int j = 0; j < 5; j++)
        {
            if (V[j][i] == -1)
                continue;
            cout << name[j] << V[j][i];
            if (j < 4)
                cout << ", ";
        }
        cout << "\n";
    }

    // Print Vertical
    for (int j = 0; j < 5; j++)
    {
        if (!cons[j + 5])
            continue;
        for (int i = 0; i < 5; i++)
        {
            if (V[j][i] == -1)
                continue;
            cout << name[j] << V[j][i];
            if (i < 4)
                cout << ", ";
        }
        cout << "\n";
    }

    // Print Upper-Left to Lower-Right
    if (cons[10])
        for (int i = 0; i < 5; i++)
        {
            if (V[i][i] == -1)
                continue;
            cout << name[i] << V[i][i];
            if (i < 4)
                cout << ", ";
        }

    // Print Lower-Left to Upper-Right
    if (cons[11])
        for (int i = 0; i < 5; i++)
        {
            if (V[i][4 - i] == -1)
                continue;
            cout << name[i] << V[i][4 - i];
            if (i < 4)
                cout << ", ";
        }
}

int main()
{
    string name = "BINGO", in;
    vector<vector<int>> V(5, vector<int>(5));
    vector<bool> BingoConditions(12);

    getline(cin >> ws, in);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> in;
            if (in == "*")
                V[j][i] = -1;
            else
                V[j][i] = stoi(in);
        }
    }

    auto NUMS = V;

    int cnt = 0;
    while (cin >> in)
    {
        cnt++;
        int col = name.find(in[0]); // Get column number from the letter
        int num = stoi(in.substr(1));
        *(find(V[col].begin(), V[col].end(), num)) = -1; // Mark the number

        if (checkBingo(V, BingoConditions))
            break;
    }

    cout << cnt << "\n";

    printBingo(NUMS, BingoConditions, name);

    return 0;
}