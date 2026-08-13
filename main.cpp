#include <iostream>

struct Vector2 {
      double x;
      double y;
   };

struct Body {
   double m;
   Vector2 position;
   Vector2 velocity;
   Vector2 acceleration;
};

Vector2 add(Vector2 a, Vector2 b) {
   Vector2 result{};

   result.x = a.x + b.x;
   result.y = a.y + b.y;
   return result;
}

int main() {

   Body earth{};
   earth.m = 5.972e24;

   earth.position.x = 1.496e11;
   earth.position.y = 0;

   earth.velocity.x = 0;
   earth.velocity.y = -29780;

   earth.acceleration.x = 0.0;
   earth.acceleration.y = -9.8;

   const double dt = 1.0; // sec

   while (true) {
      earth.position.x += earth.velocity.x * dt + 0.5 * earth.acceleration.x * dt * dt;
      earth.position.y += earth.velocity.y * dt + 0.5 * earth.acceleration.y * dt * dt;

      earth.velocity.x += earth.acceleration.x * dt;
      earth.velocity.y += earth.acceleration.y * dt;
      std::cout << "Position: " << earth.position.x << "," << earth.position.y << " " << "Velocity: " << earth.velocity.x << "," << earth.velocity.y << "\n";
   }
}


