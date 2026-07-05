#pragma once
#include "box.hpp"

class Renderer {
	public:
		void Render(const Box& box, const SimCamera& cam) {
			BeginDrawing();
				ClearBackground(BLACK);
				Vec2 topLeft = box.GetPosition() - (Vec2){box.GetSize().x * 0.5f, box.GetSize().y * -0.5f};
				DrawRectangle(cam.WorldToScreen(topLeft).x, cam.WorldToScreen(topLeft).y, cam.WorldToScreen(box.GetSize().x), cam.WorldToScreen(box.GetSize().y), BLUE);
			EndDrawing();
		}
	private:

};
