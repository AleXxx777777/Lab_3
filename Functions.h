//
// Created by Acer Aspire on 29.04.2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Dychotomia_class {
private:
  double left_limit;
  double right_limit;
  double tolerance;

public:
  Dychotomia_class();
  ~Dychotomia_class();


  void setlimits(double left, double right);
  void setTolerance(double tol);

  double dichotomymethod();
  double newtonmethod();
};

#endif //FUNCTIONS_H
