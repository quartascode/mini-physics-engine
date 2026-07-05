#include "raylib.h"
#include "renderer.hpp"

int main() {
	SimCamera cam({0, 0}, 80.0f, 800, 600);

	WorldBounds bounds(cam);

	Renderer renderer;

	Box box({0, 0}, 0.5, 0.5, 20);

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();
		box.UpdateMovement(dt);
		box.BorderCollision(bounds);

		renderer.Render(box, cam);
	}
}
