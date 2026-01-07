#include <iostream>
#include <string>
#include <utility> 

using namespace std;

int main() {
    // Create pairs to store student records
    // (score, name)
    pair<int, string> student_alice = {95, "Alice"};
    pair<int, string> student_bob = make_pair(98, "Bob");
    pair<int, string> student_charlie(98, "Charlie");
    

    cout << "--- Comparing Students (Default Output) ---" << endl;
    cout << "Alice: Score " << student_alice.first << ", Name " << student_alice.second << endl;
    cout << "Bob:   Score " << student_bob.first << ", Name " << student_bob.second << endl;
    cout << "Charlie: Score " << student_charlie.first << ", Name " << student_charlie.second << endl;
    cout << "------------------------------------------\n" << endl;


    // --- CASE 1: Comparing pairs with different .first elements ---
    cout << "CASE 1: Comparing Bob vs. Alice (different scores)" << endl;
    cout << "Is Bob's record > Alice's record?  " << (student_bob > student_alice) << endl;
    cout << "// This is 1 (true) because 98 > 95.\n" << endl;
 

    // --- CASE 2: Comparing pairs with equal .first elements ---
    cout << "CASE 2: Comparing Charlie vs. Bob (same score)" << endl;
    cout << "Is Charlie's record > Bob's record?  " << (student_charlie > student_bob) << endl;
    cout << "// This is 1 (true) because their scores are equal, and \"Charlie\" > \"Bob\".\n" << endl;

    // Let's check the opposite to be sure.
    cout << "Is Bob's record > Charlie's record?  " << (student_bob > student_charlie) << endl;
    cout << "// This is 0 (false), for the same reason as above.\n" << endl;

    return 0;
}