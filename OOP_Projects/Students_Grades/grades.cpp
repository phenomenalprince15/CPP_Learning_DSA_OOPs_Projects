#include <iostream>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>

class Student {
private:
    char* name;
    int age;
    std::vector<int> grades;

public:
    Student(const char* n, int a, const std::vector<int>& g) : age(a), grades(g) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy Constructor
    Student(const Student& s) {
        age = s.age;
        grades = s.grades;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
    }

    // Copy assignment
    Student& operator=(const Student& s) {
        if (this != &s) {
            delete[] name;
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
            age = s.age;
            grades = s.grades;
        }
        return *this;
    }

    // Move Constructor
    Student(Student&& s) noexcept : name(s.name), age(s.age), grades(std::move(s.grades)) {
        s.name = nullptr;
    }

    // Move assignment
    Student& operator=(Student&& s) noexcept {
        if (this != &s) {
            delete[] name;
            name = s.name;
            age = s.age;
            grades = std::move(s.grades);
            s.name = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Student() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    const std::vector<int>& getGrades() const {
        return grades;
    }

    double calculateAvgGrades() const {
        if (grades.empty()) return 0.0;
        int sum = 0;
        for (int grade : grades) sum += grade;
        return static_cast<double>(sum) / grades.size();
    }
};

void addStudent(std::vector<std::unique_ptr<Student>>& students, const char* name, int age, const std::vector<int>& grades) {
    students.push_back(std::make_unique<Student>(name, age, grades));
}

void removeStudent(std::vector<std::unique_ptr<Student>>& students, const char* name) {
    auto it = std::remove_if(students.begin(), students.end(),
    [name](const std::unique_ptr<Student>& student) {
        return strcmp(student->getName(), name) == 0;
    });
    students.erase(it, students.end());
}

void displayStudents(const std::vector<std::unique_ptr<Student>>& students) {
    for (const auto& student : students) {
        std::cout << "Name: " << student->getName() << ", Age: " << student->getAge() << ", Average grade: "
                  << student->calculateAvgGrades() << std::endl;
    }
}

int main() {
    std::vector<std::unique_ptr<Student>> students;

    addStudent(students, "Prince", 20, {90, 90, 90});
    addStudent(students, "Alice", 20, {79, 91, 90});

    displayStudents(students);

    return 0;
}
