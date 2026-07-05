#pragma once
#include "vec2.hpp"
#include <raylib.h>

class SimCamera {
	public:
		SimCamera(Vec2 position, float zoom, int screenWidth, int screenHeight)
			: position(position),
			  zoom(zoom),
			  screenWidth(screenWidth),
			  screenHeight(screenHeight)
		{
			InitWindow(screenWidth, screenHeight, "engine");
			SetTargetFPS(60);
		}

		Vec2 WorldToScreen(const Vec2& v) const {
			float screenX =  (v.x - position.x) * zoom + screenWidth / 2.0f;
			float screenY = -(v.y + position.y) * zoom + screenHeight / 2.0f;
			return {screenX, screenY};
		}

		float WorldToScreen(float length) const { return length * zoom; }

		int GetScreenWidth() const { return screenWidth; }

		int GetScreenHeight() const { return screenHeight; }

		float GetZoom() const { return zoom; }

	private:
		Vec2 position;
		float zoom;
		int screenWidth;
		int screenHeight;
};
