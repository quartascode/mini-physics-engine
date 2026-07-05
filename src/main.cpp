#include "box.hpp"
#include "raylib.h"
#include "renderer.hpp"
#include "world.hpp"
#include "physics.hpp"
#include <vector>

int main() {
	SimCamera cam({0, 0}, 80.0f, 800, 600);

	WorldBounds bounds(cam);

	Renderer renderer;

	std::vector<Box> boxes;
	boxes.emplace_back(Box({1, 1}, 0.5, 0.5, 20, 0.1, RED));
	boxes.emplace_back(Box({-1, 1}, 1.6, 1, 20, 0.1, ORANGE));

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();

		for (Box& box : boxes) {
			box.UpdateMovement(dt);
			Physics::BorderCollision(bounds, box);
		}


		renderer.Render(boxes, cam);
	}
}
