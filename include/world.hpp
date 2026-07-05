#pragma once
#include "camera.hpp"

struct WorldBounds {
	WorldBounds(const SimCamera& cam) {
		right = cam.GetScreenWidth() / (cam.GetZoom() * 2);
		left = -right;
		up = cam.GetScreenHeight() / (cam.GetZoom() * 2);
		down = -up;
	}

	float left;
	float down;
	float up;
	float right;
};
