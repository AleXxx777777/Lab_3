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
  double left_limit;  // Додаємо ліву межу
  double right_limit; // Додаємо праву межу

public:
  Newton_class();
  ~Newton_class();

  void setx0(double x);
  void setTolerance(double tol);
  void setLimits(double left, double right); // Новий метод для встановлення меж
  double fx(double x);
  double fdx(double x);
  double newtonmethod();
};
#endif // FUNC_H
