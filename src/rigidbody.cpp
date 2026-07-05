#include "rigidbody.hpp"

void RigidBody::UpdateMovement(float dt) {
	velocity += acceleration * dt;
	position += velocity * dt;
}
