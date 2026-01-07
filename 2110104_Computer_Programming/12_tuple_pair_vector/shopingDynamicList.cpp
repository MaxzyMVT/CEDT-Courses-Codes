#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Create an empty vector to store our shopping list items (strings).
    vector<string> shopping_list;

    cout << "Shopping list is currently empty. Size: " << shopping_list.size() << endl;

    // Let's add items to our list. The vector will grow automatically.
    cout << "\nAdding items to the list..." << endl;
    shopping_list.push_back("Milk");
    shopping_list.push_back("Bread");
    shopping_list.push_back("Apples");
    shopping_list.push_back("Cheese");

    cout << "List now contains " << shopping_list.size() << " items." << endl;

    // We can access any item directly by its index, just like an array.
    cout << "The second item on the list is: " << shopping_list[1] << endl; // Bread

    // The most modern and easiest way to loop through a vector is a range-based for loop.
    cout << "\nHere is the complete shopping list:" << endl;
    for (const string& item : shopping_list) {
        cout << "- " << item << endl;
    }

    return 0;
}