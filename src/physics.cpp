#include "physics.hpp"

void Physics::BorderCollision(RigidBody& rb, const WorldBounds& bounds, const Vec2& size) {
	float halfWidth = size.x / 2.0;
	float halfHeight = size.y / 2.0;

	Vec2 pos = rb.Position();
	Vec2 vel = rb.Velocity();
	float rest = rb.Restitution();
	bool collided = false;

	if (pos.x >= bounds.right - halfWidth) {
		pos.x = bounds.right - halfWidth;
		vel.x = -vel.x * rest;
	}
	if (rb.Position().x <= bounds.left + halfWidth) {
		pos.x = bounds.left + halfWidth;
		vel.x = -vel.x * rest;
	}
	if (rb.Position().y >= bounds.up - halfHeight) {
		pos.y = bounds.up - halfHeight;
		vel.y = -vel.y * rest;
	}
	if (rb.Position().y <= bounds.down + halfHeight) {
		pos.y = bounds.down + halfHeight;
		vel.y = -vel.y * rest;
	}

	if (collided) {
		rb.SetPosition(pos);
		rb.SetVelocity(vel);
	}
}
