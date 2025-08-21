#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int A[100], B[100];
    bool isSorted = false;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int sorted = 0;      // varaible for count how many sorted pancake
    bool top_Mx = false; // varaible for flip-flop method

    do
    {
        isSorted = true;
        int Mx_pos = 0;

        // Find Max pancake
        do
        {
            // Check if Max pancake already sorted
            if (Mx_pos == n - 1 - sorted)
            {
                top_Mx = false;
                sorted++;
            }

            Mx_pos = 0;
            for (int i = 1; i < n; i++)
            {
                if (i < n - sorted && A[i] > A[Mx_pos])
                    Mx_pos = i;
                if (A[i] < A[i - 1])
                    isSorted = false;
            }

        } while (Mx_pos == n - 1 - sorted);

        // Print the row
        cout << A[0] << " ";
        for (int i = 1; i < n; i++)
            cout << A[i] << " ";

        // Check if Max pancake already on top
        if (Mx_pos == 0)
            top_Mx = true;

        // Turn every unsorted pancake
        if (top_Mx)
        {
            for (int i = 0; i < (n - sorted) / 2; i++)
                swap(A[i], A[(n - 1) - sorted - i]);
            top_Mx = false;
            sorted++;
        }

        // Turn from top to Max pancake
        else
        {
            for (int i = 0; i < (Mx_pos + 1) / 2; i++)
                swap(A[i], A[Mx_pos - i]);
            top_Mx = true;
        }

        cout << "\n";

    } while (!isSorted);

    return 0;
}