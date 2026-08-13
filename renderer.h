#pragma once

#include "physics.h"

void initializeRenderer();
void renderBody(const Body& body);
void closeRenderer();

void renderFrame(const Body& a1, const Body& a2);