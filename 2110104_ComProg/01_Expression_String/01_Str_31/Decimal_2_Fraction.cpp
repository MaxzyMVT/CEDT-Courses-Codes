#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    string integerPart, decimalPart, repeatingPart;
    long long X, Xp, numerator, denominator, GCD;

    cin >> integerPart >> decimalPart >> repeatingPart;

    int shift = pow(10, repeatingPart.size());

    X = stoll(integerPart + decimalPart + repeatingPart);
    Xp = X * shift;

    denominator = (shift - 1) * pow(10, decimalPart.size());
    numerator = (Xp - X + stoll(repeatingPart)) / shift;

    GCD = gcd(numerator, denominator);

    cout << numerator / GCD << " / " << denominator / GCD << "\n";

    return 0;
}