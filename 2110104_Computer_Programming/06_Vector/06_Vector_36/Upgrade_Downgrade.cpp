#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> grades = {"A", "B+", "B", "C+", "C", "D+", "D", "F"};
    vector<tuple<int, int, string>> students; // Grade, Order, ID
    string in;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string grade;
        cin >> in >> grade;

        int pos = find(grades.begin(), grades.end(), grade) - grades.begin();
        students.push_back({pos, i, in});
    }

    while (cin >> in)
    {
        char command = in.back();
        in.pop_back();

        auto itr = students.begin();
        while (itr != students.end() && get<2>(*itr) != in)
            itr++;
        int &grade = get<0>(*itr);

        if (command == '+')
            grade = max(0, grade - 1);
        else
            grade = min(7, grade + 1);
    }

    sort(students.begin(), students.end());

    for (auto student : students)
    {
        cout << get<2>(student) << " " << grades[get<0>(student)] << "\n";
    }

    return 0;
}
