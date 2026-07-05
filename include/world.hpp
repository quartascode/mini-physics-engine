#pragma once
#include "camera.hpp"

struct WorldBounds {
	WorldBounds(const SimCamera& cam) {
		right = cam.ScreenWidth() / (cam.Zoom() * 2);
		left = -right;
		up = cam.ScreenHeight() / (cam.Zoom() * 2);
		down = -up;
	}

	float left;
	float down;
	float up;
	float right;
};
