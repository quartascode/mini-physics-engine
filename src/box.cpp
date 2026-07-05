#include "box.hpp"

void Box::BorderCollision(const WorldBounds& bounds){
	float halfWidth = size.x / 2.0;
	float halfHeight = size.y / 2.0;
	if (position.x >= bounds.right - halfWidth) {
		position.x = bounds.right - halfWidth;
		velocity.x = -velocity.x * restitution;
	}
	if (position.x <= bounds.left + halfWidth) {
		position.x = bounds.left + halfWidth;
		velocity.x = -velocity.x * restitution;
	}
	if (position.y >= bounds.up - halfHeight) {
		position.y = bounds.up - halfHeight;
		velocity.y = -velocity.y * restitution;
	}
	if (position.y <= bounds.down + halfHeight) {
		position.y = bounds.down + halfHeight;
		velocity.y = -velocity.y * restitution;
	}
}
