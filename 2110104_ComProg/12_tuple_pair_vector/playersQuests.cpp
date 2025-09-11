#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to print the current state of the quest log neatly.
// This helps us see the result of each operation.
void print_quests(const string& title, const vector<string>& quests) {
    cout << "--- " << title << " ---" << endl;
    if (quests.empty()) {
        cout << "The quest log is empty." << endl;
    } else {
        for (int i = 0; i < quests.size(); ++i) {
            cout << i << ": " << quests[i] << endl;
        }
    }
    cout << "------------------------\n" << endl;
}

int main() {
    // Start with a vector containing a few quests.
    vector<string> quest_log = {"Defeat the Dragon", "Find the Lost Sword", "Gather 5 Herbs"};
    print_quests("Initial Quest Log", quest_log);


    // STEP 1: Use push_back() to add new quests to the end of the log.
    cout << ">>> Player accepts two new quests...\n";
    quest_log.push_back("Explore the Cave");
    quest_log.push_back("Deliver a Message");
    print_quests("After push_back()", quest_log);


    // STEP 2: Use pop_back() to remove the very last item.
    // The player decides the last quest isn't worth their time.
    cout << ">>> Player abandons the last quest they accepted...\n";
    quest_log.pop_back();
    print_quests("After pop_back()", quest_log);


    // STEP 3: Use erase() to remove a specific quest from the middle.
    // The player has completed "Find the Lost Sword", which is at index 1.
    cout << ">>> Player completes 'Find the Lost Sword' (at index 1). Removing it...\n";
    // To use erase, we need an iterator. v.begin() points to the start.
    // v.begin() + 1 points to the element at index 1.
    quest_log.erase(quest_log.begin() + 1);
    print_quests("After erase()", quest_log);


    // STEP 4: Use insert() to add a new quest somewhere in the middle.
    // An urgent quest appears and must be done soon! Let's put it second on the list (at index 1).
    cout << ">>> An URGENT quest appears! Inserting it at the second position (index 1)...\n";
    // Similar to erase, insert takes an iterator to specify the position.
    // The new element is inserted *before* the element at the iterator's position.
    quest_log.insert(quest_log.begin() + 1, "URGENT: Defend the Village");
    print_quests("After insert()", quest_log);

    return 0;
}