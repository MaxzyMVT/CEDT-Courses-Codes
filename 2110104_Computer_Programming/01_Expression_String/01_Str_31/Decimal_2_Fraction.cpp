#include <iostream> 
#include <cmath>
 
using namespace std; 

long gcd(long a, long b) { 
    if (b == 0) return a; 
    return gcd(b, a%b); 
}

int main() { 
    
    string integerPart, fractionPart, repeatingPart;
    long long X, Xp, numerator, denominator, GCD;

    cin >> integerPart >> fractionPart >> repeatingPart;

    int shift = pow(10, repeatingPart.size());

    X = stoll(integerPart + fractionPart + repeatingPart);
    Xp = X * shift;

    denominator = (shift - 1) * pow(10, fractionPart.size());
    numerator = (Xp - X + stoll(repeatingPart)) /shift;

    GCD = gcd(numerator, denominator);


    cout << numerator / GCD << " / " << denominator / GCD << "\n";

    
    return 0;
}