#include "physics.hpp"

void Physics::BorderCollision(RigidBody& rb, const Vec2& size) {
	float halfWidth = size.x / 2.0;
	float halfHeight = size.y / 2.0;

	Vec2 pos = rb.Position();
	Vec2 vel = rb.Velocity();
	float rest = rb.Restitution();
	bool collided = false;

	if (pos.x >= worldBounds.right - halfWidth) {
		pos.x = worldBounds.right - halfWidth;
		vel.x = -vel.x * rest;
		collided = true;
	}
	if (pos.x <= worldBounds.left + halfWidth) {
		pos.x = worldBounds.left + halfWidth;
		vel.x = -vel.x * rest;
		collided = true;
	}
	if (pos.y>= worldBounds.up - halfHeight) {
		pos.y = worldBounds.up - halfHeight;
		vel.y = -vel.y * rest;
		collided = true;
	}
	if (pos.y <= worldBounds.down + halfHeight) {
		pos.y = worldBounds.down + halfHeight;
		vel.y = -vel.y * rest;
		collided = true;
	}

	if (collided) {
		rb.SetPosition(pos);
		rb.SetVelocity(vel);
	}
}
