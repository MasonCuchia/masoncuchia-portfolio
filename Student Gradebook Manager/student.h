#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>


class Student {
    public:
    Student(std::string name);
    std::string getName() const;
    void addGrade(double grade);
    void printGrades() const;
    double calculateAverage() const;
    std::vector<double> getGrades() const { return grades; }
    private:
    std::string name;
    std::vector<double> grades;
};

#endif