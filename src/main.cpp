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
	boxes.emplace_back(Box(0.5, 0.5, BLUE, {0, 0}, 20, 0.5));
	boxes.emplace_back(Box(1.0, 0.8, ORANGE, {-1, -1}, 90, 0.5));

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();

		for (int i = 0; i < boxes.size(); i++) {
			boxes[i].GetRigidBody().UpdateMovement(dt);
			sim.BorderCollision(boxes[i].GetRigidBody(), boxes[i].Size());
			for (int j = i+1; j < boxes.size(); j++) {
				sim.BoxCollision(boxes[i], boxes[j]);
			}
		}


		renderer.Render(boxes, cam);
	}
}
