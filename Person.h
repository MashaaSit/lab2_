
#include <vector>
#include <string>
#include <iomanip>

class Person {
protected:
    std::string name;
    std::vector<std::vector<double>> roots; // Вектор векторов для корней
    std::vector<std::vector<double>> coefficients; // Вектор векторов для коэффициентов

public:
    Person(const std::string& name) : name(name) {}

    virtual void solveEquations() = 0; // Чисто виртуальная функция

    const std::string& getName() const { return name; }
    const std::vector<std::vector<double>>& getRoots() const { return roots; }

    void addRoots(const std::vector<double>& newRoots) {
        roots.push_back(newRoots);
    }

    void setCoefficients(const std::vector<std::vector<double>>& coeffs) {
        coefficients = coeffs;
    }

    void readCoefficientsFromFile(const std::string& filename);
};

