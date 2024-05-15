#include <bits/stdc++.h>
using namespace std;

class poligons {
private:
  int number;
  float size;

public:
  poligons(int n, float d) {
    if (n > 2 && d > 0) {
      number = n;
      size = d;
    } else
      cout << "Invalid values for a poligon \n";
  }

  float getSize() { return size; }

  float sumAngles() {
    float sum;
    sum = 180 * (number - 2);

    return sum;
  }

  float perimeter() {
    float p;
    p = number * (size);

    return p;
  }
};

class triangule : public poligons {
public:
  triangule(float d) : poligons(3, d) {}

  float area() {
    float s, len;
    len = getSize();
    s = len * len * sqrt(3) / 2;
    return s;
  }
};

class squares : public poligons {
public:
  squares(float d) : poligons(4, d) {}

  float area() {
    float s, len;
    len = getSize();
    s = len * len;
    return s;
  }
};

int main() {

  triangule t1(2.5);
  squares s1(3.7);

  cout << t1.area() << "\n";
  cout << s1.area() << "\n";
}