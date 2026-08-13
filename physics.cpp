#include "physics.h"
#include <cmath>


PhysicsVector3 add(PhysicsVector3 a, PhysicsVector3 b) {
    PhysicsVector3 result{};

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}
PhysicsVector3 subtract(PhysicsVector3 a, PhysicsVector3 b) {
    PhysicsVector3 result{};

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

PhysicsVector3 multiply(PhysicsVector3 a, double scalar) {
    PhysicsVector3 result{};

    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;
    return result;
}

double magnitude(PhysicsVector3 v) {
    double c = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    return c;
}

PhysicsVector3 gravitationalAcceleration(Body a, Body b){
    PhysicsVector3 r = subtract(b.position, a.position);  // Vector from A to B
    PhysicsVector3 direction = multiply(r, 1.0/magnitude(r));

    double acceleration = ((1.0) * (b.m))/(magnitude(r) * magnitude(r)); // G = 1
    return multiply(direction, acceleration);
}
