#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int day, month, year, totalDays = 0;
    cin >> day >> month >> year;

    // Convert year from BE to AD
    year -= 543;

    // Check if year is a leap year
    bool isLeap = (year % 4 == 0 && year % 100) || (year % 400 == 0);

    if(month > 1)
        totalDays += 31; // January
    if(month > 2)
        totalDays += 28 + isLeap; // February  
    if(month > 3)
        totalDays += 31; // March
    if(month > 4)
        totalDays += 30; // April
    if(month > 5)
        totalDays += 31; // May
    if(month > 6)
        totalDays += 30; // June
    if(month > 7)
        totalDays += 31; // July
    if(month > 8)
        totalDays += 31; // August
    if(month > 9)
        totalDays += 30; // September
    if(month > 10)
        totalDays += 31; // October
    if(month > 11)
        totalDays += 30; // November
    if(month > 12)
        totalDays += 31; // December

    cout << totalDays + day;

    return 0;
}