#include <iostream>
#include <utility>

using namespace std;

// This function finds and returns both the min and max from an array
pair<int, int> findMinMax(int arr[], int size) {
    if (size == 0) {
        return make_pair(0, 0); // Or handle error appropriately
    }

    int min_val = arr[0];
    int max_val = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return make_pair(min_val, max_val);
}

int main() {
    
    int numbers[] = {40, 11, 8, 92, 53, 22};
    pair<int, int> result = findMinMax(numbers, 6);
    
    cout << "In the array, the minimum value is " << result.first << endl;
    cout << "And the maximum value is " << result.second << endl;
    
    return 0;
}