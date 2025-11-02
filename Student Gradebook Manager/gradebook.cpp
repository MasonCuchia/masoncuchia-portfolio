#include <iostream>
#include <fstream>
#include "gradebook.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Gradebook::addStudent(const string& name){
    students.push_back(Student(name));
}

Student* Gradebook::findStudent(const string& name){
    for(Student& student : students){
        if(student.getName() == name){
            return &student;
        }
    }
    return nullptr;
}

void Gradebook::removeStudent(const string& name){
    for(int i = 0; i < students.size(); ++i){
        if(students[i].getName() == name){
            students.erase(students.begin() + i);
            cout << "Student removed." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void Gradebook::listStudents() const{
    if(students.empty()){
        cout << "No students in the gradebook." << endl;
        return;
    }
    for(const Student& student : students){
        cout << student.getName() << " - Grades: ";
        student.printGrades();
        cout << " | Average: " << student.calculateAverage() << endl;
    }
    cout << endl;
}

void Gradebook::saveToFile(const string& filename) const{
    ofstream outFile(filename);
    if(!outFile){
        cout << "Error opening file for writing." << endl;
        return;
    }
    for(const Student& student : students){
        outFile << student.getName() << " ";
        for (double grade : student.getGrades()) {
            outFile << grade << " ";
        }
        outFile << endl;
    }
    cout << "Data saved." << endl;
}


void Gradebook::loadFromFile(const string& filename){
    ifstream inFile(filename);
    if (!inFile){
        cout << "Error opening file for reading.\n";
        return;
    }
    students.clear();
    string line;
    while(getline(inFile, line)){
        if(line.empty()) continue;
        stringstream ss(line);
        string name;
        ss >> name;

        Student newStudent(name);
        double grade;
        while(ss >> grade){
            newStudent.addGrade(grade);
        }
        students.push_back(newStudent);
    }
    cout << "Data loaded." << endl;
}