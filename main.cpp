#include "Functions.h"
#include <iostream>

using namespace std;

int main() {
    system("chcp 65001 > nul");

    Dychotomia_class* dyh = new Dychotomia_class();
    dyh->setlimits(0, 0.8);
    dyh->setTolerance(1e-6);
    double root_dichotomy = dyh->dichotomymethod();
    cout << "Корінь з методом Дихотомії: " << root_dichotomy << endl;
    delete dyh;

    Newton_class* newton = new Newton_class();
    newton->setx0(0.3);
    newton->setTolerance(1e-7);
    double root_newton = newton->newtonmethod();
    cout << "Корінь з методом Ньютона: " << root_newton << endl;
    delete newton;

    return 0;
}
