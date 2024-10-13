#include "Person.h"

class Teacher {
    std::vector<std::pair<std::string, std::vector<double>>> emails; // Письма на проверку
    std::map<std::string, int> results; // Результаты студентов

public:
    void receiveEmails(const std::vector<std::pair<std::string, std::vector<double>>>& newEmails);

    void checkSolutions(const std::vector<Person*>& students);

    void publishResults(const std::string& filename);
};
