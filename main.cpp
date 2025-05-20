#include "Functions.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    system("chcp 65001 > nul");

    Dychotomia_class* dyh = new Dychotomia_class();
    dyh->setlimits( 0, 0.8);
    dyh->setTolerance(1e-6);
    double root_dichotomy = dyh->dichotomymethod();
    cout << "Корінь з методом Дихотомії: " << root_dichotomy << endl;
    delete dyh;

    Newton_class* newton = new Newton_class();
    newton->setx0( 0.6);
    newton->setTolerance( 1e-6);
    newton->setLimits( 0, 0.8);
    double root_newton = newton->newtonmethod();
    if (!std::isnan(root_newton)) {
        cout << "Корінь з методом Ньютона: " << root_newton << endl;
    } else {
        cout << "Не вдалося знайти корінь з методом Ньютона." << endl;
    }
    delete newton;

    return 0;
}