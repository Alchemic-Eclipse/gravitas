# Gravitas

A C++ N-body gravitational simulatior (and a lot more)

Basically, I wanted to see what happens when you let multiple bodies pull on each other through gravity and then just... let the physics do its thing.

I'm building this from scratch while learning C++, so the goal isn't just to make a simulation that works. I also want to understand the physics, the numerical methods, and the C++ behind it.

## What is this?

In an N-body system, every body gravitationally interacts with every other body.

For two bodies, Sir Isaac Newton gave us:

$$
F = G\frac{m_1m_2}{r^2}
$$

Though for N bodies, things get a little more interesting because every body has to account for the gravitational pull from all the others.

So for each body, we calculate the total force acting on it and use that to update it's motion over time.

Simple enough.

Until you actually try to simulate it 🗿✌🏻

## Physics

The simulation is based on classical Newtonian mechanics.

For each body:

$$
\mathbf{F} = m\mathbf{a}
$$

and the gravitational force between two bodies is

$$
\mathbf{F}_{ij}
=
G\frac{m_i m_j}{r_{ij}^2}\hat{\mathbf r}_{ij}
$$

The total force on a body is the vector sum of the gravitational force from every other body.

The interesting part is what happens after repeating this calculational thousands of times.

Especially when the system stops behaving nicely. Because apparently 3 objects interacting through gravity wasn't complicated enough. 😭🤷🏻‍♂️

## Goals

I don't want this to just be a pretty animation of planets going in circles.

I want to use it ti explore things like:

- orbital dynamics
- conservation of energy
- conservation of momentum
- center of mass
- numerical integration (of various types)
- stability and numerical error
- chaotic systems
- different initial conditions
- how small changes can competely change a system's future

## Planned Features

- [ ] Basic two-body simulation
- [ ] General N-body simulation
- [ ] Numerical integration
- [ ] Real-time visualizzation
- [ ] Adjustable simulation parameters
- [ ] Orbital trails
- [ ] Energy conservation monitoring
- [ ] Momentum conservatuon monitoring
- [ ] Center-of-mass tracking
- [ ] Collision handling
- [ ] Multiple predefined systems
- [ ] User-defined bodies
- [ ] Performance improvements
- [ ] Documentation of the numerical methods

## Tech Stack
- C++
- CMake
- [Visualization library]

## Why C++?

I'm currently learning C++, and this seemed like a much better way to learn it than making another random calculator or guessing-game program.

It also makes sense for a simulation like this since eventually I want to experiment with larger numbers of bodies and better numerical methods.

So this project is partly a physics project, partly a computational physics project, and partly me finding increasingly complicated ways to make C++ complain 🐈

## Project Status

🟨 In development

The simulation is being built step by step, starting from the basic physics and gradually adding more functionality.

The goal is to understand each part rather than just simply throw together a working program and pretend I know why it works...

#### Thank you...!
