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

double magnitude(Vector3 v) {
   double c = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
   return c;
}

Vector3 gravitationalAcceleration(Body a, Body b){
   Vector3 r = subtract(b.position, a.position);  // Vector from A to B
   Vector3 direction = multiply(r, 1.0/magnitude(r));

   double acceleration = ((1.0) * (b.m))/(magnitude(r) * magnitude(r)); // G = 1
   return multiply(direction, acceleration);
}

int main() {

   // Body earth{};
   // earth.m = 5.972e24;
   const double dt = 0.001; // sec
   //
   // earth.position.x = 1.496e11;
   // earth.position.y = 0;
   // earth.position.z = 0;
   //
   // earth.velocity.x = 0;
   // earth.velocity.y = 29780;
   // earth.velocity.z = 0;


   Body a1{1,0,0,0,0,0.2236,0};
   Body a2{1,10,0,0,0,-0.2236,0};

   while (true) {
      // std::cout << acc1.x << "," << acc1.y << "," << acc1.z << "," << "\n";
      Vector3 acc1 = gravitationalAcceleration(a1, a2);
      Vector3 acc2 = gravitationalAcceleration(a2, a1);

      a1.velocity = add(a1.velocity, multiply(acc1, dt));
      a1.position = add(a1.position, multiply(a1.velocity, dt));

      a2.velocity = add(a2.velocity, multiply(acc2, dt));
      a2.position = add(a2.position, multiply(a2.velocity, dt));

      std::cout << a1.position.x << ", " << a1.position.y << ", " << a1.position.z << "..... " << a1.velocity.x << ", " << a1.velocity.y << ", " << a1.velocity.z << "\n";

   }
}


