#include <iostream>
#include <tuple>

using namespace std;

int main() {
    // Storing race results as (minutes, seconds, bib_number)
    tuple<int, int, int> runner_a = make_tuple(10, 30, 115); // 10m 30s
    tuple<int, int, int> runner_b = make_tuple(10, 25, 204); // 10m 25s
    tuple<int, int, int> runner_c = make_tuple(10, 25, 101); // 10m 25s (lower bib)

    // The comparison starts with the first element (minutes).
    // If they are equal, it moves to the second (seconds), and so on.
    
    // runner_b is faster than runner_a because 25 < 30
    if (runner_b < runner_a) {
        cout << "Runner B is faster than Runner A." << endl;
    }

    // runner_b and runner_c have the same time. The tie is broken by the bib number.
    // 101 < 204, so runner_c comes "first" in a sorted list.
    if (runner_c < runner_b) {
        cout << "Runner C (bib " << get<2>(runner_c) 
             << ") places just ahead of Runner B (bib " << get<2>(runner_b) 
             << ") due to the tie-breaker." << endl;
    }
    
    return 0;
}