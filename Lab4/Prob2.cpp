#include <bist/stdc++.h>
using namespace std;


void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
struct Student {
    string name;
    string className;
    float mathGrade;
    float physicalGrade;
    float average;
};


void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin.ignore(); 
    getline(cin, newStudent.name);
    cout << "Enter class name: ";
    getline(cin, newStudent.className);
    cout << "Enter math grade: ";
    cin >> newStudent.mathGrade;
    cout << "Enter physical grade: ";
    cin >> newStudent.physicalGrade;

    newStudent.average = (newStudent.mathGrade + newStudent.physicalGrade) / 2.0;

    students.push_back(newStudent);

    cout << "Student added successfully." << endl;
}

void searchStudentByName(const vector<Student>& students, const string& searchName) {
    bool found = false;
    for (const auto& student : students) {
        if (student.name == searchName) {
            cout << "Student found:" << endl;
            cout << "Name: " << student.name << endl;
            cout << "Class: " << student.className << endl;
            cout << "Math Grade: " << student.mathGrade << endl;
            cout << "Physical Grade: " << student.physicalGrade << endl;
            cout << "Average: " << student.average << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void sortStudentsByAverage(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.average > s2.average;
    });
}

int main() {
    indef();
    vector<Student> students;

    while (true) {
        cout << "1. Add a new student" << endl;
        cout << "2. Search a student by name" << endl;
        cout << "3. Sort the list in descending order based on average" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                string searchName;
                cout << "Enter student name to search: ";
                cin.ignore(); 
                getline(cin, searchName);
                searchStudentByName(students, searchName);
                break;
            case 3:
                sortStudentsByAverage(students);
                cout << "List sorted successfully." << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
