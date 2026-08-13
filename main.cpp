#include <iostream>
#include <cmath>

struct Vector3 {
      double x;
      double y;
      double z;
   };

struct Body {
   double m;
   Vector3 position;
   Vector3 velocity;
   Vector3 acceleration;
};

Vector3 add(Vector3 a, Vector3 b) {
   Vector3 result{};

   result.x = a.x + b.x;
   result.y = a.y + b.y;
   result.z = a.z + b.z;
   return result;
}
Vector3 subtract(Vector3 a, Vector3 b) {
   Vector3 result{};

   result.x = a.x - b.x;
   result.y = a.y - b.y;
   result.z = a.z - b.z;
   return result;
}

Vector3 multiply(Vector3 a, double scalar) {
   Vector3 result{};

   result.x = a.x * scalar;
   result.y = a.y * scalar;
   result.z = a.z * scalar;
   return result;
}

double magnitude(Vector3 a) {
   double c = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
   return c;
}

int main() {

   Body earth{};
   earth.m = 5.972e24;

   earth.position.x = 1.496e11;
   earth.position.y = 0;
   earth.position.z = 0;

   earth.velocity.x = 0;
   earth.velocity.y = 29780;
   earth.velocity.z = 0;

   const double dt = 1.0; // sec

   // Testing
   Vector3 a {1.0, 1.0, 1.0};

   std::cout << magnitude(a);
}


