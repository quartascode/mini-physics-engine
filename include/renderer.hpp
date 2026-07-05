#pragma once
#include "box.hpp"
#include "camera.hpp"
#include <vector>

class Renderer {
	public:
		void Render(const std::vector<Box>& boxes, const SimCamera& cam) {
			BeginDrawing();
				ClearBackground(BLACK);

				for (const Box& box : boxes) {
					// Make the center of the object (position) the top left point to render
					Vec2 topLeft = box.GetRigidBody().Position() - (Vec2){box.Size().x * 0.5f, box.Size().y * -0.5f};
					DrawRectangle(cam.WorldToScreen(topLeft).x, cam.WorldToScreen(topLeft).y, cam.WorldToScreen(box.Size().x), cam.WorldToScreen(box.Size().y), box.BoxColor());
				}

			EndDrawing();
		}
	private:

};
