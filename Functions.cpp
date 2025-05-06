#include "Functions.h"
#include <cmath>
#include <iostream>

double fx(double x) {
    double t = tan(x);
    return t - (pow(t, 3) + 1) / 3.0 + 0.2 * pow(t, 5);
}

double fdx(double x) {
    double t = tan(x);
    double sec2 = 1.0 / (cos(x) * cos(x)); // sec^2(x)
    double df = (1 - t * t); // derivative of tan(x) = sec^2(x)

    // Derivative using chain rule:
    return (1 - t * t)
           - (1.0 / 3.0) * (3 * pow(t, 2) * sec2)
           + 0.2 * 5 * pow(t, 4) * sec2;
}

Dychotomia_class::Dychotomia_class() {}
Dychotomia_class::~Dychotomia_class() {}

void Dychotomia_class::setlimits(double left, double right) {
    left_limit = left;
    right_limit = right;
}

void Dychotomia_class::setTolerance(double tol) {
    tolerance = tol;
}

double Dychotomia_class::dichotomymethod() {
    double a = left_limit;
    double b = right_limit;
    double x;

    while (fabs(b - a) > tolerance) {
        x = (a + b) / 2;
        if (fx(x) * fx(a) < 0)
            b = x;
        else
            a = x;
    }

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

double Newton_class::newtonmethod() {
    double x = x0;
    double x_next;

    while (true) {
        double f = fx(x);
        double df = fdx(x);

        if (df == 0) break; // запобігання діленню на 0

        x_next = x - f / df;

        if (fabs(x_next - x) < tolerance)
            break;

        x = x_next;
    }

    return x_next;
}
