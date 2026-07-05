#pragma once

struct Vec2 {
	float x;
	float y;

	Vec2 operator+(const Vec2& v) const {
		return {x + v.x, y + v.y};
	}
	Vec2 operator-(const Vec2& v) const {
		return {x - v.x, y - v.y};
	}
	Vec2 operator*(const Vec2& v) const {
		return {x * v.x, y * v.y};
	}
	Vec2 operator*(const float k) const {
		return {x * k, y * k};
	}
	Vec2& operator+=(const Vec2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
};	
