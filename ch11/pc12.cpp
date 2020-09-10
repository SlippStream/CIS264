//Nick Zimanski - CIS264
//8 September 2020

#include <iostream>
using namespace std;
const string DIV = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
struct Student {
    string name;
    int idnum;
    int* tests;
    double avg;
    char grade;
};
Student calcGrade(Student s, int k) {
    double a = 0;
    for (int i=0;i<k;i++) {
        a += s.tests[i];
    }
    s.avg = a / k;
    if (s.avg > 90) s.grade = 'A';
    else if (s.avg > 80) s.grade = 'B';
    else if (s.avg > 70) s.grade = 'C';
    else if (s.avg > 60) s.grade = 'D';
    else s.grade = 'F';
    return s;
}
void displayStudents(Student s[], int k) {
    for (int i =0; i< k; i++) {
        cout << s[i].name << " - #" << s[i].idnum << endl;
        cout << s[i].grade << " (" << s[i].avg << ")\n";
    }
}
int main() {
    int s, t, i, j;
    cout << "Please enter the number of students: ";
    cin >> s;
    cout << "Please enter the number of tests per student: ";
    cin >> t;
    Student* students = new Student[s];
    for (i=0;i<s;i++) {
        cout << "Please enter the name of student " << i+1 << ": ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Please enter an id number for " << students[i].name << ": ";
        cin >> students[i].idnum;
        students[i].tests = new int(t);

        for (j=0;j<t;j++) {
            do {
            cout << "Please enter score " << j+1 << " for " << students[i].name << ": ";
            cin >> students[i].tests[j];
            } while (students[i].tests[j] < 0);
        }
        students[i] = calcGrade(students[i], t);
    }
    displayStudents(students, s);
    return 0;
}