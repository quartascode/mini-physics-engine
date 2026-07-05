#pragma once
#include "vec2.hpp"	
#include "world.hpp"

class Box {
	public:
		Box(Vec2 position, float width, float height, float mass)
			: position(position),
			size({width, height}),
			velocity({0, 0}),
			acceleration({0, -9.81}),
			restitution(0.1),
			mass(mass)
		{}

		const Vec2& GetPosition() const { return position; }

		const Vec2& GetSize() const { return size; }

		void UpdateMovement(float dt) {
			velocity += acceleration * dt;
			position += velocity * dt;
		}

		void BorderCollision(const WorldBounds& bounds);
			
	private:
		Vec2 position;
		Vec2 size;
		Vec2 velocity;
		Vec2 acceleration;
		float restitution;
		float mass;
};
