#pragma once
#include "box.hpp"
#include <vector>

class Renderer {
	public:
		void Render(const std::vector<Box>& boxes, const SimCamera& cam) {
			BeginDrawing();
				ClearBackground(BLACK);

				for (const Box& box : boxes) {
					Vec2 topLeft = box.Position() - (Vec2){box.Size().x * 0.5f, box.Size().y * -0.5f};
					DrawRectangle(cam.WorldToScreen(topLeft).x, cam.WorldToScreen(topLeft).y, cam.WorldToScreen(box.Size().x), cam.WorldToScreen(box.Size().y), box.BoxColor());
				}

			EndDrawing();
		}
	private:

};
