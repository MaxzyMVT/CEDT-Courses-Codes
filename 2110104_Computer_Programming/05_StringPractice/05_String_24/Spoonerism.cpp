#include <iostream>
#include <string>

using namespace std;

int dis(int i, int j)
{
    if (i > j)
        swap(i, j);
    return j - i + 1;
}

int main()
{
    string in;
    getline(cin, in);

    int first_space_pos = 0;
    int last_space_pos = 0;
    int first_vowel_pos = 0;
    int last_vowel_pos = 0;

    for (int i = 0; i < in.size(); i++)
    {
        int x = in[i];
        if (x == ' ')
        {
            if (first_space_pos == 0)
                first_space_pos = i;
            last_space_pos = i;
            last_vowel_pos = 0;
        }
        if (string("aeiou").find(x) != string::npos)
        {
            if (first_vowel_pos == 0)
                first_vowel_pos = i;
            if (last_vowel_pos == 0)
                last_vowel_pos = i;
        }
    }

    cout << in.substr(0, first_vowel_pos) +
                in.substr(last_vowel_pos) +
                in.substr(first_space_pos, dis(first_space_pos, last_space_pos)) +
                in.substr(last_space_pos + 1, dis(last_space_pos + 1, last_vowel_pos - 1)) +
                in.substr(first_vowel_pos, dis(first_vowel_pos, first_space_pos - 1));

    return 0;
}