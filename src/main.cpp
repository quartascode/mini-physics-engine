#include "box.hpp"
#include "raylib.h"
#include "renderer.hpp"
#include <vector>
#include "physics.hpp"

int main() {
	SimCamera cam({0, 0}, 80.0f, 800, 600);

	WorldBounds bounds(cam);

	Physics sim(bounds);

	Renderer renderer;

	std::vector<Box> boxes;
	boxes.emplace_back(Box(0.5, 0.5, BLUE, {0, 0}, 20, 1.0));
	boxes.emplace_back(Box(1.0, 0.8, ORANGE, {-1, -1}, 90, 1.0));

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();

		for (Box& box : boxes) {
			box.GetRigidBody().UpdateMovement(dt);
			sim.BorderCollision(box.GetRigidBody(), box.Size());
			for (Box& boxPrime : boxes) {
				sim.BoxCollision(box, boxPrime);
			}
		}


		renderer.Render(boxes, cam);
	}
}
