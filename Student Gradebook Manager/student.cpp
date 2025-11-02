#include <iostream>
#include <vector>
#include <string>

#include "student.h"
using namespace std;

Student::Student(string name) : name(name) {}
string Student::getName() const { return name; }
void Student::addGrade(double grade) { grades.push_back(grade); }

void Student::printGrades() const{
    if (grades.empty()) return;
    for (double grade : grades) cout << grade << " ";
}

double Student::calculateAverage() const {
    if (grades.empty()) return 0.0;
    double sum = 0;
    for (double grade : grades) sum += grade;
    return sum / grades.size();
}