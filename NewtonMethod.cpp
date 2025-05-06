#include "NewtonMethod.h"
#include <cmath>

NewtonMethod::NewtonMethod() {
    left_limit = 0;
    right_limit = 1;
    tolerance = 1e-6;
}

NewtonMethod::~NewtonMethod() {}

void NewtonMethod::setLimits(double left, double right) {
    left_limit = left;
    right_limit = right;
}

void NewtonMethod::setTolerance(double tol) {
    tolerance = tol;
}

double NewtonMethod::f(double x) {
    double tg = tan(x);
    return tg - (pow(tg, 3) + 1) / 3.0 + 0.2 * pow(tg, 5);
}

double NewtonMethod::df(double x) {
    double sec2 = 1 / (cos(x) * cos(x));
    double tg = tan(x);
    return sec2 * (1 + pow(tg, 4));
}

double NewtonMethod::findRoot() {
    double x = (left_limit + right_limit) / 2.0;

    while (true) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12)
            break; // захист від ділення на 0

        double x_next = x - fx / dfx;

        if (fabs(x_next - x) < tolerance)
            return x_next;

        x = x_next;
    }

    return x;
}
