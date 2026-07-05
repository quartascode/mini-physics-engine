#pragma once
#include "vec2.hpp"	
#include <raylib.h>

class Box {
	public:
		Box(Vec2 position, float width, float height, float mass, float restitution, Color color)
			: position(position),
			size({width, height}),
			velocity({0, 0}),
			acceleration({0, -9.81}),
			restitution(restitution),
			mass(mass),
			color(color)
		{}

		Vec2& Position() { return position; }

		Vec2& Velocity() { return velocity; }

		const Vec2& Size() const { return size; }

		const float& Restitution() const { return restitution; }

		const Color& BoxColor() const { return color; }

		void UpdateMovement(float dt) {
			velocity += acceleration * dt;
			position += velocity * dt;
		}
			
	private:
		Vec2 position;
		Vec2 size;
		Vec2 velocity;
		Vec2 acceleration;
		float restitution;
		float mass;
		Color color;
};
