#pragma once

struct PhysicsVector3 {
    double x;
    double y;
    double z;
};

struct Body {
    double m;
    PhysicsVector3 position;
    PhysicsVector3 velocity;
    PhysicsVector3 acceleration;
};

PhysicsVector3 add(PhysicsVector3 a, PhysicsVector3 b);
PhysicsVector3 subtract(PhysicsVector3 a, PhysicsVector3 b);
PhysicsVector3 multiply(PhysicsVector3 a, double scalar);

double magnitude(PhysicsVector3 v);

PhysicsVector3 gravitationalAcceleration(Body a, Body b);