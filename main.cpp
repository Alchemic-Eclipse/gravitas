#include <iostream>

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


}


