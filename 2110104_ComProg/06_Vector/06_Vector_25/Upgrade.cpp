#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> grades = {"F", "D", "D+", "C", "C+", "B", "B+", "A", "A"};
    vector<pair<string, string>> students;
    string in;

    cin >> in;
    while (in != "q")
    {
        string grade;
        cin >> grade;

        students.push_back({in, grade});

        cin >> in;
    }

    while (cin >> in)
    {
        auto itr = students.begin();
        while (itr != students.end() && itr->first != in)
            itr++;

        string old_grade = itr->second;
        itr->second = *(find(grades.begin(), grades.end(), old_grade) + 1);
    }

    for (auto student : students)
    {
        cout << student.first << " " << student.second << "\n";
    }

    return 0;
}