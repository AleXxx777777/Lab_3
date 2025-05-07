#ifndef FUNC_H
#define FUNC_H

class Dychotomia_class {
private:
  double left_limit;
  double right_limit;
  double tolerance;

  static double fx(double x);

public:
  Dychotomia_class();
  ~Dychotomia_class();

  void setlimits(double left, double right);
  void setTolerance(double tol);
  double dichotomymethod();
};

class Newton_class {
private:
  double x0;
  double tolerance;

  static double fx(double x);
  static double fdx(double x);

public:
  Newton_class();
  ~Newton_class();

  void setx0(double x);
  void setTolerance(double tol);
  double newtonmethod();
};

#endif // FUNC_H
