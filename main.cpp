#include <iostream>
#include <raylib.h>

#include "physics.h"
#include "renderer.h"

bool paused = false;

int main() {

   double dt = 0.005; // sec

    Body initialA1{1, 0, 0, 0, 0.2, 0.25, 0};
    Body initialA2{1, 10, 0, 0, 0, 0.1, -0.1};

    Body a1 = initialA1;
    Body a2 = initialA2;

   initializeRenderer();

   while (!WindowShouldClose()) {

       if (IsKeyPressed(KEY_SPACE)) {
           paused = !paused;
       }

       if (IsKeyPressed(KEY_R)) {
           a1 = initialA1;
           a2 = initialA2;

           resetTrails();
       }

       // Physics Update
       if (!paused) {

           PhysicsVector3 acc1 = gravitationalAcceleration(a1, a2);
           PhysicsVector3 acc2 = gravitationalAcceleration(a2, a1);

           a1.velocity = add(a1.velocity, multiply(acc1, dt));
           a1.position = add(a1.position, multiply(a1.velocity, dt));

           a2.velocity = add(a2.velocity, multiply(acc2, dt));
           a2.position = add(a2.position, multiply(a2.velocity, dt));
       }

       updateCamera();

       // Rendering
       renderFrame(a1, a2);
   }

   closeRenderer();
   return 0;

}