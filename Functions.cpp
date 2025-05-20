#include "Functions.h"
#include <cmath>
#include <iostream>

Dychotomia_class::Dychotomia_class() {}
Dychotomia_class::~Dychotomia_class() {}

void Dychotomia_class::setlimits(double left, double right) {
    left_limit = left;
    right_limit = right;
}

void Dychotomia_class::setTolerance(double tol) {
    tolerance = tol;
}

double Dychotomia_class::fx(double x) {
    double t = tan(x);
    return t - (pow(t, 3) + 1) / 3.0 + 0.2 * pow(t, 5);
}

double Dychotomia_class::dichotomymethod() {
    double a = left_limit; // Ініціалізація лівої межі відрізка
    double b = right_limit; // Ініціалізація правої межі відрізка
    double x; // Змінна для середини відрізка

    // Повторюємо, поки довжина відрізка [a, b] більша за задану точність
    while (fabs(b - a) > tolerance) {
        x = (a + b) / 2; // Обчислюємо середину відрізка
        // Перевіряємо, чи корінь лежить у лівій половині [a, x]
        if (fx(x) * fx(a) < 0)
            b = x; // Якщо так, звужуємо відрізок, змінюючи праву межу
        else
            a = x; // Інакше звужуємо відрізок, змінюючи ліву межу
    }

    // Повертаємо середину відрізка як наближення до кореня
    return (a + b) / 2;
}

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setx0(double x) {
    x0 = x;
}

void Newton_class::setTolerance(double tol) {
    tolerance = tol;
}
void Newton_class::setLimits(double left, double right) {
    left_limit = left;
    right_limit = right;
}
double Newton_class::fx(double x) {
    double t = tan(x);
    return t - (pow(t, 3) + 1) / 3.0 + 0.2 * pow(t, 5);
}

double Newton_class::fdx(double x) {
    double t = tan(x);
    double sec2 = 1.0 / (cos(x) * cos(x)); // sec^2(x)
    return (1 - t * t + pow(t, 4)) * sec2;
}
double Newton_class::newtonmethod() {
    double x = x0; // Ініціалізація початкового наближення
    double x_next; // Змінна для наступного наближення
    const double EPSILON = 1e-10; // Мала константа для перевірки похідної

    // Перевірка, чи початкове наближення в межах
    if (x < left_limit || x > right_limit) {
        x = (left_limit + right_limit) / 2; // Якщо x0 поза межами, починаємо з середини діапазону
    }

    try {
        while (true) {
            double f = fx(x); // Обчислення значення функції f(x)
            double df = fdx(x); // Обчислення значення похідної f'(x)

            // Перевірка, чи похідна не занадто мала
            if (fabs(df) < EPSILON) {
                throw std::runtime_error("Похідна близька до нуля, метод Ньютона не може продовжити обчислення.");
            }

            // Обчислення наступного наближення
            x_next = x - f / df;

            // Перевірка, чи нове наближення в межах
            if (x_next < left_limit || x_next > right_limit) {
                throw std::runtime_error("Наближення вийшло за межі заданого діапазону.");
            }

            // Якщо різниця між послідовними наближеннями менша за точність, зупиняємо ітерації
            if (fabs(x_next - x) < tolerance) {
                break;
            }

            // Перевірка на NaN або Infinity
            if (std::isnan(x_next) || std::isinf(x_next)) {
                throw std::runtime_error("Метод Ньютона дав некоректне значення (NaN або Infinity).");
            }

            // Оновлення поточного наближення
            x = x_next;
        }

        // Перевірка, чи знайдене значення є коренем
        if (fabs(fx(x_next)) > tolerance) {
            throw std::runtime_error("Знайдене значення не є коренем (функція не наближається до нуля).");
        }

        return x_next;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Помилка в методі Ньютона: " << e.what() << std::endl;
        return std::numeric_limits<double>::quiet_NaN(); // Повертаємо NaN у разі помилки
    }
}