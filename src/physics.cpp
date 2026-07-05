#include "physics.hpp"
#include "box.hpp"

void Physics::BorderCollision(const WorldBounds& bounds, Box& box){
	Vec2 halfSize = box.Size() / 2.0;
	Vec2 position = box.Position();
	Vec2 velocity = box.Velocity();
	float restitution = box.Restitution();
	if (position.x >= bounds.right - halfSize.x) {
		position.x = bounds.right - halfSize.x;
		velocity.x = -velocity.x * restitution;
	}
	if (position.x <= bounds.left + halfSize.x) {
		position.x = bounds.left + halfSize.x;
		velocity.x = -velocity.x * restitution;
	}
	if (position.y >= bounds.up - halfSize.y) {
		position.y = bounds.up - halfSize.y;
		velocity.y = -velocity.y * restitution;
	}
	if (position.y <= bounds.down + halfSize.y) {
		position.y = bounds.down + halfSize.y;
		velocity.y = -velocity.y * restitution;
	}
}
