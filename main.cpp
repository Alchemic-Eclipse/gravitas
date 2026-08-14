#include <iostream>
#include <raylib.h>

#include "physics.h"
#include "renderer.h"

int main() {

   const double dt = 0.005; // sec

   Body a1{1,0,0,0,0.0,-0.2236,0};
   Body a2{1,10,0,0,0,0.2236,0};

   initializeRenderer();

   while (!WindowShouldClose()) {

      // // Physics Update
      PhysicsVector3 acc1 = gravitationalAcceleration(a1, a2);
      PhysicsVector3 acc2 = gravitationalAcceleration(a2, a1);

      a1.velocity = add(a1.velocity, multiply(acc1, dt));
      a1.position = add(a1.position, multiply(a1.velocity, dt));

      a2.velocity = add(a2.velocity, multiply(acc2, dt));
      a2.position = add(a2.position, multiply(a2.velocity, dt));

      // Rendering
     renderFrame(a1, a2);

   }


   closeRenderer();
   return 0;

}


