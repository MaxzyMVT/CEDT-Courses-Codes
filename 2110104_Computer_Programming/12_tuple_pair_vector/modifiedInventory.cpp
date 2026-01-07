#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;

// Helper function to print our inventory neatly
void print_inventory(const string& title, const vector<pair<string, int>>& inventory) {
    cout << "--- " << title << " ---" << endl;
    for (const auto& item : inventory) {
        // item.first refers to the string (product name)
        // item.second refers to the int (quantity)
        cout << "Product: " << item.first << ", Stock: " << item.second << endl;
    }
    cout << "-----------------------\n" << endl;
}

int main() {
    // A vector where each element is a pair of (string, int)
    vector<pair<string, int>> inventory = {
        {"Apples", 50},
        {"Oranges", 75},
        {"Bananas", 120}
    };

    // Show the initial state of our inventory
    print_inventory("Initial Inventory", inventory);

    cout << ">>> Simulating a sale: decreasing stock of each item by 1...\n" << endl;

    // This is the key part!
    // We use a reference '&' to get a direct alias to the original pair in the vector.
    // The type of 'item' is now 'pair<string, int>&'.
    for (pair<string, int>& item : inventory) {
    
        // We are now modifying the original item's stock count directly.
        item.second--; // Decrease the integer part of the pair
    }

    // Show the final state. The original data in the vector has been changed.
    print_inventory("Final Inventory", inventory);

    return 0;
}