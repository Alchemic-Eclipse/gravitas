#include "renderer.h"
#include "raylib.h"
#include <vector>

Camera3D camera;
std::vector<Vector3> trail1;
std::vector<Vector3> trail2;

void initializeRenderer() {
    InitWindow(1450, 800, "Gravitas");

    camera.position = {5.0f, 10.0f, 10.0f};
    camera.target = {5.0f, 0.0f, -4.9f};
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

    DrawSphere(position, 0.2f, DARKBLUE);
}

void closeRenderer() {
    CloseWindow();
}

void renderFrame(const Body &a1, const Body &a2) {

    static int frameCounter = 0;
    frameCounter++;

    if (frameCounter % 50 == 0) {
        Vector3 position1 = {
            static_cast<float>(a1.position.x),
            static_cast<float>(a1.position.y),
            static_cast<float>(a1.position.z)
        };

        Vector3 position2 = {
            static_cast<float>(a2.position.x),
            static_cast<float>(a2.position.y),
            static_cast<float>(a2.position.z)
        };

        trail1.push_back(position1);
        trail2.push_back(position2);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);

    renderBody(a1);
    renderBody(a2);

    for (size_t i = 0; i + 1 < trail1.size(); i++) {
        DrawLine3D(trail1[i], trail1[i + 1], GREEN);
    }

    for (size_t i = 0; i + 1 < trail2.size(); i++) {
        DrawLine3D(trail2[i], trail2[i + 1], BLUE);
    }

    // DrawGrid(20, 1.0f);

    EndMode3D();
    EndDrawing();

}

void updateCamera() {

    PhysicsVector3 forward = {
        camera.target.x - camera.position.x,
        camera.target.y - camera.position.y,
        camera.target.z- camera.position.z
    };

    double length = magnitude(forward);

    forward.x /= length;
    forward.y /= length;
    forward.z /= length;

    float speed = 0.01f;


    if (IsKeyDown(KEY_W)) {
        camera.position.z += forward.z * speed;
    }
    if (IsKeyDown(KEY_S)) {
        camera.position.z -= forward.z * speed;

    }

    // if (IsKeyDown(KEY_A)) {
    //     camera.position.x -= 0.01f;
    // }
    // if (IsKeyDown(KEY_D)) {
    //     camera.position.x += 0.01f;
    // }
}
