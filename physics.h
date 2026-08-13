#pragma once

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

Vector3 add(Vector3 a, Vector3 b);
Vector3 subtract(Vector3 a, Vector3 b);
Vector3 multiply(Vector3 a, double scalar);

double magnitude(Vector3 v);

Vector3 gravitationalAcceleration(Body a, Body b);