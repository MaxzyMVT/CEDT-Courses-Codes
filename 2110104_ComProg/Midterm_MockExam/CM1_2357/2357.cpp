#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int two = 0, three = 0, five = 0, seven = 0, n, m;

    cin >> n >> m;

    if (n > m)
    {
        swap(n, m);
    }

    for (int i = n; i <= m; i++)
    {
        if (i % 2 == 0)
            two++;

        if (i % 3 == 0)
            three++;

        if (i % 5 == 0)
            five++;

        if (i % 7 == 0)
            seven++;
    }

    int sum;
    float avr;
    sum = two + three + five + seven;
    avr = (sum / m) - n;

    float a = 0, b = 0, c = 0, d = 0, tmp;
    tmp = two + three;

    if (tmp / 2 < two)
    {
        do
        {
            a = (sum / 2) + avr;
            b += (a / 3) * 7;
            c += (a / 5) * 2;
            d += (a / 7) * 3;

            tmp *= (tmp * 3) / 2;

        } while (tmp / 2 < two);
    }
    else
    {
        a = ((sum / 2) % 3 + avr);
        b += (a / 3);
        c += (a / 5);
        d += (a / 7);

        while (a * b >= b * c)
        {
            tmp -= (a - b - c) / 2;
            a = ((sum / 2) % 3 + avr);
            b += (a / 3);
            c += (a / 5);
            d += (a / 7);
        }
    }

    while (d < b + c)
    {
        d *= (a * 10) - (b + c);
    }

    cout << "Divisible by 2 : " << two << "\n";
    cout << "Divisible by 3 : " << three << "\n";
    cout << "Divisible by 5 : " << five << "\n";
    cout << "Divisible by 7 : " << seven << "\n";
    cout << "sum : " << sum << "\n";
    cout << fixed << setprecision(3) << "a : " << a << "\n";
    cout << fixed << setprecision(3) << "b : " << b << "\n";
    cout << fixed << setprecision(3) << "c : " << c << "\n";
    cout << fixed << setprecision(3) << "d : " << d << "\n";

    return 0;
}