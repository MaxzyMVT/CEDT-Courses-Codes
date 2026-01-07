#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846

// Function to calculate the days in year
int DayOfYear(int day, int month, int year)
{

    int totalDays = 0;

    // Convert year from BE to AD
    year -= 543;

    // Check if year is a leap year
    bool isLeap = (year % 4 == 0 && year % 100) || (year % 400 == 0);

    if (month > 1)
        totalDays += 31; // January
    if (month > 2)
        totalDays += 28 + isLeap; // February
    if (month > 3)
        totalDays += 31; // March
    if (month > 4)
        totalDays += 30; // April
    if (month > 5)
        totalDays += 31; // May
    if (month > 6)
        totalDays += 30; // June
    if (month > 7)
        totalDays += 31; // July
    if (month > 8)
        totalDays += 31; // August
    if (month > 9)
        totalDays += 30; // September
    if (month > 10)
        totalDays += 31; // October
    if (month > 11)
        totalDays += 30; // November
    if (month > 12)
        totalDays += 31; // December

    return totalDays + day;
}

int main()
{

    int day1, month1, year1, day2, month2, year2;
    cin >> day1 >> month1 >> year1 >> day2 >> month2 >> year2;

    // Calculate blue range
    int blueRange = DayOfYear(day2, month2, year2) - 1;
    year2 -= 543;

    // Calculate red range
    int redRange = DayOfYear(day1, month1, year1);
    year1 -= 543;
    bool isLeap1 = (year1 % 4 == 0 && year1 % 100) || (year1 % 400 == 0);

    if (isLeap1)
        redRange = 366 - redRange + 1;
    else
        redRange = 365 - redRange + 1;

    // Calculate total days
    int totalDays = redRange + blueRange + 365 * (year2 - year1 - 1);

    // Calculate Biorhythm
    double phys = sin(2 * M_PI * totalDays / 23);
    double emo = sin(2 * M_PI * totalDays / 28);
    double intell = sin(2 * M_PI * totalDays / 33);

    cout << totalDays << " " << round(phys * 100.0) / 100.0 << " " << round(emo * 100.0) / 100.0 << " " << round(intell * 100.0) / 100.0;

    return 0;
}