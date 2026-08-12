#include "iostream"

int main() {
   struct Body {
      double m;
      double x;
      double y;
      double vx;
      double vy;
   };

   Body earth{};
   earth.m = 5.972e24;  // kg
   earth.x = 1.496e11;  // m
   earth.y = 0;
   earth.vx = 0;  // m/s
   earth.vy = -29780;

   double dt = 1.0; // sec

   earth.x += earth.vx * dt;
   earth.y += earth.vy * dt;

   std::cout << "x = " << earth.x << '\n';
   std::cout << "y = " << earth.y << '\n';

}


