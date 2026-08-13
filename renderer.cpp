#include "renderer.h"
#include "raylib.h"


Camera3D camera;

void initializeRenderer() {
    InitWindow(1200, 800, "Gravitas");

    camera.position = {5.0f, 10.0f, 10.0f};
    camera.target = {5.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void renderBody(const Body &body) {
    Vector3 position = {
        static_cast<float>(body.position.x),
        static_cast<float>(body.position.y),
        static_cast<float>(body.position.z)
    };

    DrawSphere(position, 0.2f, BLUE);
}

void closeRenderer() {
    CloseWindow();
}

void renderFrame(const Body &a1, const Body &a2) {
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);

    renderBody(a1);
    renderBody(a2);

    DrawGrid(20, 1.0f);

    EndMode3D();
    EndDrawing();

}
