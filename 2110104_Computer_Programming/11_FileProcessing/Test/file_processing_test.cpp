#include <iostream>
#include <fstream> // For file input/output
#include <vector>
#include <algorithm> // For sort

using namespace std;

int main()
{
    // 2 Ways to declare / open a file
    ifstream inputFile("in.txt");
    ofstream outputFile;
    outputFile.open("out.txt");

    // Check if files are opened successfully
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<int> nums;
    int n;

    // Loop as long as there is input (Also works for getline(inputFile, line) for strings)
    while (inputFile >> n)
    {
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    for (auto x : nums)
    {
        outputFile << x << " ";
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}