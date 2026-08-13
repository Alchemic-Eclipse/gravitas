#include "physics.h"
#include <cmath>


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
