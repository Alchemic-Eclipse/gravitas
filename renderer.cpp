#include "renderer.h"
#include "raylib.h"
#include <vector>

Camera3D camera;
std::vector<Vector3> trail1;
std::vector<Vector3> trail2;

void initializeRenderer() {
    InitWindow(1200, 800, "Gravitas");

    camera.position = {5.0f, 10.0f, 10.0f};
    camera.target = {5.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void renderBody(const Body &body, std::vector<Vector3>& trail) {
    Vector3 position = {
        static_cast<float>(body.position.x),
        static_cast<float>(body.position.y),
        static_cast<float>(body.position.z)
    };

    trail.push_back(position);

    if (trail.size() > 500) {
        trail.erase(trail.begin());
    }

    DrawSphere(position, 0.2f, DARKBLUE);
}

void closeRenderer() {
    CloseWindow();
}

void renderFrame(const Body &a1, const Body &a2) {
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);

    renderBody(a1, trail1);
    renderBody(a2, trail2);

    for (size_t i = 0; i + 1 < trail1.size(); i++) {
        DrawLine3D(trail1[i], trail1[i + 1], GREEN);
    }

    for (size_t i = 0; i + 1 < trail2.size(); i++) {
        DrawLine3D(trail2[i], trail2[i + 1], BLUE);
    }

    DrawGrid(20, 1.0f);

    EndMode3D();
    EndDrawing();

}
