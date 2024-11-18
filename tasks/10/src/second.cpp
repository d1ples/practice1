#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

struct Student {
    std::string name;
    int grade;
};


std::vector<Student> insert_students() {
    int count;

    std::cout << "How much?\n";
    std::cin >> count;

    std::vector<Student> students(count);

    for (Student& student : students) {
        std::cout << "Student name: ";
        std::cin >> student.name;

        std::cout << "Student grade: ";
        std::cin >> student.grade;
    }

    return students;
}

bool comparator(const Student& a, const Student& b) {
    return a.grade > b.grade;
}

int main() {
    std::vector<Student> students = insert_students();

    std::sort(students.begin(),students.end(),comparator);

    for (const Student& student : students) {
        std::cout << student.name << " got a grade of " << student.grade << "\n";
    }

    return 0;
}

