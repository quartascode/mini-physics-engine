#pragma once
#include "rigidbody.hpp"
#include "vec2.hpp"	
#include <raylib.h>

class Box {
	public:
		Box(float width, float height, Color color, Vec2 position, float mass, float restitution)
			: size({width, height}),
			color(color),
			rigidBody(position, mass, restitution)
		{}

		const Vec2& Size() const { return size; }

		const Color& BoxColor() const { return color; }

		const RigidBody& GetRigidBody() const { return rigidBody; }

		RigidBody& GetRigidBody() { return rigidBody; }
			
	private:
		Vec2 size;
		Color color;
		RigidBody rigidBody;
};
