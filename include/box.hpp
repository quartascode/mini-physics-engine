#pragma once
#include "vec2.hpp"	
#include "world.hpp"
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

		const Vec2& Position() const { return position; }

		const Vec2& Size() const { return size; }

		void UpdateMovement(float dt) {
			velocity += acceleration * dt;
			position += velocity * dt;
		}

		void BorderCollision(const WorldBounds& bounds);

		const Color& BoxColor() const { return color; }
			
	private:
		Vec2 position;
		Vec2 size;
		Vec2 velocity;
		Vec2 acceleration;
		float restitution;
		float mass;
		Color color;
};
