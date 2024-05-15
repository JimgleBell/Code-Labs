#include <cmath>
#include <iostream>
using namespace std;

class points {
private:
  float x, y, z;

public:
  points() { x, y, z = 0; }

  points(float a, float b, float c) : x(a), y(b), z(c){};

  points oposite() const {
    points ops;
    ops.x = -x;
    ops.y = -y;
    ops.z = -z;

    return ops;
  }

  float Distance(points p2) const {
    float dist;
    dist = sqrt(pow(p2.x - x, 2) + pow(p2.y - y, 2) + pow(p2.z - z, 2));

    return dist;
  }

  void visualize() const { printf("(%.0f,%.0f,%.0f)\n", x, y, z); }
};

int main() {

  points p1(1, 2, 3), p2(2, 4, 5), p3;

  p1.visualize();
  p2.visualize();
  p1.oposite().visualize();
  p3.visualize();
}