#include "Functions.h"
#include "iostream"
#include <cmath>

Dychotomia_class::Dychotomia_class()  {
    left_limit = 0;
    right_limit = 0.8;
    tolerance = 1e-6;
}

Dychotomia_class::~Dychotomia_class()  {}

void Dychotomia_class::setlimits (double left, double right) {
    left_limit = left;
    right_limit = right;
}

void Dychotomia_class::setTolerance(double tol) {
    tolerance = tol;
}


double f(double x) {
    double tg = tan(x);
    return tg - (pow(tg, 3) + 1) / 3.0 + 0.2 * pow(tg, 5);
}


double df(double x) {
    double tg = tan(x);
    double sec2 = 1 / (cos(x) * cos(x)); // sec^2(x)
    double tg2 = tg * tg;
    double tg4 = tg2 * tg2;
    return sec2 * (1 - tg2 + 0.2 * 5 * tg4 + 3 * tg2 * 0.2 * tg4);
}

double Dychotomia_class::dichotomymethod() {
    double a = left_limit;
    double b = right_limit;
    double x;

    while (fabs(b - a) > tolerance) {
        x = (a + b) / 2;
        if (f(x) > 0)
            b = x;
        else
            a = x;
    }

    return (a + b) / 2;
}

double Dychotomia_class::newtonmethod() {
    double x0 = (left_limit + right_limit) / 2.0;
    double x = x0;

    while (true) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-10) {
            std::cerr << "Derivative too small!" << std::endl;
            return x;
        }

        double x_next = x - fx / dfx;

        if (fabs(x_next - x) < tolerance)
            return x_next;

        x = x_next;
    }
}
