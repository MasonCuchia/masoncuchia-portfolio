#include <iostream>
#include <limits>
#include "gradebook.h"
using namespace std;

void printMenu();

int main(){
    Gradebook gradebook;
    cout << "WELCOME TO THE GRADEBOOK" << endl << endl;
    while(true){
        int choice = 0;
        printMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1: {
                string name;
                cout << "Enter student name: ";
                getline(cin, name);
                gradebook.addStudent(name);
                break;
            }

            case 2: {
                string name;
                int grade;
                cout << "Enter student name: ";
                getline(cin, name);
                Student* student = gradebook.findStudent(name);
                if (student) {
                    cout << "Enter grade: ";
                    cin >> grade;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    student->addGrade(grade);
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 3: {
                gradebook.listStudents();
                break;
            }

            case 4: {
                string name;
                cout << "Enter student name to remove: ";
                getline(cin, name);
                gradebook.removeStudent(name);
                break;
            }

            case 5: {
                gradebook.saveToFile("grades.txt");
                cout << "Saved to grades.txt\n";
                break;
            }

            case 6: {
                gradebook.loadFromFile("grades.txt");
                cout << "Loaded from grades.txt\n";
                break;
            }

            case 7:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

void printMenu(){
    cout << "\n===== STUDENT GRADEBOOK MENU =====\n" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add a grade to student" << endl;
    cout << "3. Show all students and averages" << endl;
    cout << "4. Remove Student" << endl;
    cout << "5. Save gradebook to file" << endl;
    cout << "6. Load gradebook from file" << endl;
    cout << "7. Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}