#include "box.hpp"
#include "raylib.h"
#include "renderer.hpp"
#include <vector>

int main() {
	SimCamera cam({0, 0}, 80.0f, 800, 600);

	WorldBounds bounds(cam);

	Renderer renderer;

	std::vector<Box> boxes;
	boxes.emplace_back(Box(0.5, 0.5, BLUE, {0, 0}, 20, 0.1));
	boxes.emplace_back(Box(1.0, 0.8, ORANGE, {-1, -1}, 90, 0.1));

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();

		for (Box& box : boxes) {
			box.GetRigidBody().UpdateMovement(dt);
			box.GetRigidBody().BorderCollision(bounds, box.Size());
		}


		renderer.Render(boxes, cam);
	}
}
