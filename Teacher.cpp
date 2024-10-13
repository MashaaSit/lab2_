#include "Teacher.h"


void Teacher::receiveEmails(const std::vector<std::pair<std::string, std::vector<double>>> &newEmails) {
    emails.insert(emails.end(), newEmails.begin(), newEmails.end());
}

void Teacher::checkSolutions(const std::vector<Person *> &students) {
    for (const auto& email : emails) {
        const std::string& name = email.first;
        const std::vector<double>& studentRoots = email.second;

        for (const auto& student : students) {
            if (student->getName() == name) {
                int correctCount = 0;
                const auto& teacherRoots = student->getRoots();
                for (size_t i = 0; i < studentRoots.size(); ++i) {
                    if (i < teacherRoots.size() && studentRoots[i] == teacherRoots[i][0]) { // Сравнение только первого корня
                        correctCount++;
                    }
                }
                results[name] = correctCount;
            }
        }
    }
}

void Teacher::publishResults(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << std::setw(20) << "Student Name" << std::setw(20) << "Correct Solutions" << std::endl;
        for (const auto& result : results) {
            file << std::setw(20) << result.first << std::setw(20) << result.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Could not open the file!" << std::endl;
    }
}
