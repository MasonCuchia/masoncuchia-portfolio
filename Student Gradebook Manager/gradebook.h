#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <iostream>
#include <vector>
#include <string>
#include "student.h"


class Gradebook {
    public:
    void addStudent(const std::string& name);
    Student* findStudent(const std::string& name);
    void removeStudent(const std::string& name);
    void listStudents() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    private:
    std::vector<Student> students;
};

#endif