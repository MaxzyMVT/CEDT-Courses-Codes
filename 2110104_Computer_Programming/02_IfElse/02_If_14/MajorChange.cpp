#include <iostream>
#include <cmath>
using namespace std;

int main() {

    string ID1, ID2;
    double GPAX1, GPAX2;
    char grade_com_prog1, grade_com_prog2, grade_calA1, grade_calA2, grade_calB1, grade_calB2;
    bool valid1 = false, valid2 = false;

    cin >> ID1 >> GPAX1 >> grade_com_prog1 >> grade_calA1 >> grade_calB1;
    cin >> ID2 >> GPAX2 >> grade_com_prog2 >> grade_calA2 >> grade_calB2;

    // Check if 1 & 2 valid
    if(grade_com_prog1 == 'A' && grade_calA1 <= 'C' && grade_calB1 <= 'C')
        valid1 = true;
    
    if(grade_com_prog2 == 'A' && grade_calA2 <= 'C' && grade_calB2 <= 'C')
        valid2 = true;
    
    if(valid1 && !valid2)
        cout << ID1;
    else if(!valid1 && valid2)
        cout << ID2;
    else if(!valid1 && !valid2)
        cout << "None";
    else {
        
    // Cases when both are valid
        if(GPAX1 > GPAX2)
            cout << ID1;
        else if(GPAX1 < GPAX2)
            cout << ID2;
        else if(grade_calA1 < grade_calA2)
            cout << ID1;
        else if(grade_calA1 > grade_calA2)
            cout << ID2;
        else if(grade_calB1 < grade_calB2)
            cout << ID1;
        else if(grade_calB1 > grade_calB2)
            cout << ID2;
        else
            cout << "Both";
    }

    return 0;
}