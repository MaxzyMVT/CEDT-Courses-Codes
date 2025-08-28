#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void add_string(string &A, string &B)
{
    // Make A > B
    if (A.size() < B.size() || (A.size() == B.size() && A < B))
        swap(A, B);

    int len = max(A.size(), B.size());
    int remainder = 0;

    for (int i = 1; i <= len; i++)
    {

        int pos_A = A.size() - i;
        int pos_B = B.size() - i;
        int digit_A = A[pos_A] - '0';
        int digit_B = pos_B < 0 ? 0 : (B[pos_B] - '0');

        int digit_result = (digit_A + digit_B + remainder) % 10;
        remainder = (digit_A + digit_B + remainder) / 10;
        A[pos_A] = digit_result + '0';
    }

    if (remainder > 0)
    {
        A = to_string(remainder) + A;
    }
}

int main()
{
    string in = "0", sum = "0";

    do
    {
        add_string(sum, in);
        cin >> in;
    } while (in != "END");

    cout << sum;

    return 0;
}