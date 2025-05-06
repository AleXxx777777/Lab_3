#ifndef NEWTON_METHOD_H
#define NEWTON_METHOD_H

class NewtonMethod {
private:
    double left_limit;
    double right_limit;
    double tolerance;

    double f(double x);    // функція
    double df(double x);   // похідна

public:
    NewtonMethod();
    ~NewtonMethod();

    void setLimits(double left, double right);
    void setTolerance(double tol);
    double findRoot();
};

#endif
