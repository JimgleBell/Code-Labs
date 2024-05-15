#include <cmath>
#include <iostream>
using namespace std;

class complexNumbers {
private:
  float re, img;

public:
  complexNumbers(float a, float b) {
    re = a;
    img = b;
  }

  float module() {
    float mod;
    mod = sqrt(re * re + img * img);

    return mod;
  }

  complexNumbers conjugate() {
    complexNumbers conj(re, -img);

    return conj;
  }

  complexNumbers sum(complexNumbers c2) {
    float a, b;
    a = re + c2.re;
    b = img + c2.img;

    complexNumbers result(a, b);

    return result;
  }

  complexNumbers subtraction(complexNumbers c2) {
    float a, b;
    a = re - c2.re;
    b = img - c2.img;

    complexNumbers result(a, b);

    return result;
  }

  complexNumbers multiplication(complexNumbers c2) {
    float a, b;

    a = re * c2.re - img * c2.img;
    b = re * c2.img + img * c2.re;

    complexNumbers result(a, b);

    return result;
  }

  complexNumbers division(complexNumbers c2) {
    float a, b;
    complexNumbers c3(a, b);

    c3 = this->multiplication(c2.conjugate());
    c3.re = c3.re / c2.module();
    c3.img = c3.img / c2.module();

    return c3;
  }

  void print() {
    if (img > 0) {
      cout << re << " + " << img << "i";
    } else if (img < 0) {
      cout << re << " " << img << "i";
    }
  }

  ~complexNumbers() {}
};

int main() {
  complexNumbers c1(1, 1), c2(1, 1);

  complexNumbers c3 = c1.division(c2);
  c3.print();

  return 0;
}