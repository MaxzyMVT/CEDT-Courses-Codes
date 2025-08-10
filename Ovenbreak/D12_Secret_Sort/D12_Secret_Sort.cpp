#include<iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int n_check = arr[0];
    bool isSorted = true;
    for (size_t i=1; i < n; i++) {
        if(arr[i] < n_check) {
            isSorted = false;
            break;
        }
        n_check = arr[i];
    }

    switch (isSorted)
    {
        case true:
            cout << "sorted!" << endl;
            break;
    
        default:
            cout << "un-sorted!" << endl;
            break;
    }
}