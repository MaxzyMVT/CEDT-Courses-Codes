#include <iostream>
#include <string>
#include <tuple> // Required for tuple

using namespace std;

int main() {
    // Create a tuple to store a student's record
    // (Name, Student ID, GPA)
    
    // Method 1: The original make_tuple helper function
    //tuple<string, int, double> student1 = make_tuple("Alice", 101, 3.85);
    
    // Method 2: Brace Initialization (modern and readable)
    tuple<string, int, double> student1 = {"Bob", 102, 3.72};
    
    // Method 3: Direct Constructor Call
    //tuple<string, int, double> student1("Charlie", 103, 3.95);

    // Access and print the elements
    cout << "Student Name: " << get<0>(student1) << endl;
    cout << "Student ID: " << get<1>(student1) << endl;
    cout << "GPA: " << get<2>(student1) << endl;

    // We can modify the elements as well
    get<2>(student1) = 3.91; // Alice's GPA improved
    cout << "Updated GPA: " << get<2>(student1) << endl;
    
    return 0;
}