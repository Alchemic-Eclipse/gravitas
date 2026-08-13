// #include "iostream"

int main() {

   struct Vector2 {
      double x;
      double y;
   };

   struct Body {
      double m;
      Vector2 position;
      Vector2 velocity;
   };

   Body earth{};
   earth.m = 5.972e24;

   earth.position.x = 1.496e11;
   earth.position.y = 0;

   earth.velocity.x = 0;
   earth.velocity.y = -29780;

   double dt = 1.0; // sec

   earth.position.x += earth.velocity.x * dt;
   earth.position.y += earth.velocity.y * dt;

}


