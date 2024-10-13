#include "Student.h"

#include <bits/random.h>

inline void GoodStudent::solveEquations() {
    for (const auto& coeff : coefficients) {
        double a = coeff[0];
        double b = coeff[1];
        double c = coeff[2];
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            addRoots({root1, root2});
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            addRoots({root});
        } else {
            addRoots({});
        }
    }
}

void AverageStudent::solveEquations() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (const auto& coeff : coefficients) {
        double a = coeff[0];
        double b = coeff[1];
        double c = coeff[2];
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            if (dis(gen) > 0.5) { // 50% шанс на правильный ответ
                double root1 = (-b + sqrt(discriminant)) / (2 * a);
                double root2 = (-b - sqrt(discriminant)) / (2 * a);
                addRoots({root1, root2});
            } else {
                addRoots({0}); // Ошибка
            }
        } else if (discriminant == 0) {
            if (dis(gen) > 0.5) {
                double root = -b / (2 * a);
                addRoots({root});
            } else {
                addRoots({0}); // Ошибка
            }
        } else {
            addRoots({}); // Нет решения
        }
    }
}

void BadStudent::solveEquations() {
    for (const auto& coeff : coefficients) {
        addRoots({0}); // Всегда считает, что корень один и это 0
    }
}

