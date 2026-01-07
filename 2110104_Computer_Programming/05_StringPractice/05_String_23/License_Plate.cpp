#include <iostream>
#include <string>

using namespace std;

int plate_to_num(string &in)
{
    int num = 0;
    int digit_mul = 1;
    for (int i = 6; i >= 0; i--)
    {
        if (i == 3)
            continue;

        if (i == 1 || i == 2)
        {
            num += digit_mul * (in[i] - 'A');
            digit_mul *= 26;
        }
        else
        {
            num += digit_mul * (in[i] - '0');
            digit_mul *= 10;
        }
    }
    return num;
}

string num_to_plate(int num)
{
    string plate = "";
    int digit_mul = 10 * 26 * 26 * 10 * 10 * 10;
    for (int i = 1; i <= 6; i++)
    {
        if (i == 4)
            plate += "-";

        if (i != 2 && i != 3)
        {
            digit_mul /= 10;
            plate += (num / digit_mul + '0');
            num %= digit_mul;
        }
        else
        {
            digit_mul /= 26;
            plate += (num / digit_mul + 'A');
            num %= digit_mul;
        }
    }
    return plate;
}

int main()
{
    string in;
    int n;

    cin >> in >> n;

    n += plate_to_num(in);
    cout << num_to_plate(n);

    return 0;
}