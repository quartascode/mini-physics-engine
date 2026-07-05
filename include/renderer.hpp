#pragma once
#include "box.hpp"
#include <vector>

class Renderer {
	public:
		void Render(const std::vector<Box>& boxes, const SimCamera& cam) {
			BeginDrawing();
				ClearBackground(BLACK);

				for (const Box& box : boxes) {
					Vec2 topLeft = box.GetPosition() - (Vec2){box.GetSize().x * 0.5f, box.GetSize().y * -0.5f};
					DrawRectangle(cam.WorldToScreen(topLeft).x, cam.WorldToScreen(topLeft).y, cam.WorldToScreen(box.GetSize().x), cam.WorldToScreen(box.GetSize().y), BLUE);
				}

			EndDrawing();
		}
	private:

};
