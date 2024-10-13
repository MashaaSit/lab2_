#include <fstream>
#include <iostream>

#include "Student.h"
#include "Teacher.h"



auto createStudentsFromFile(const std::string &filename, std::vector<Person *> &students) -> void {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name, type;
        ss >> name >> type;

        if (type == "good") {
            students.push_back(new GoodStudent(name));
        } else if (type == "average") {
            students.push_back(new AverageStudent(name));
        } else if (type == "bad") {
            students.push_back(new BadStudent(name));
        }
    }
    file.close();
}

int main() {
    std::vector<Person*> students;
    createStudentsFromFile("/home/masha/CLionProjects/допса/lab2/lab2-dev-branch/students_list.txt", students);

    std::vector<std::pair<std::string, std::vector<double>>> emails;

    // Чтение коэффициентов и решение уравнений
    for (auto& student : students) {
        student->readCoefficientsFromFile("/home/masha/CLionProjects/допса/lab2/lab2-dev-branch/coefficients.txt");
        student->solveEquations();

        // Формирование письма
        emails.push_back({student->getName(), student->getRoots().back()}); // Последний вектор корней
    }

    Teacher teacher;
    teacher.receiveEmails(emails);
    teacher.checkSolutions(students);
    teacher.publishResults("results.txt");

    // Освобождение памяти
    for (auto& student : students) {
        delete student;
    }

    return 0;
}
