#include "rigidbody.hpp"

void RigidBody::UpdateMovement(float dt) {
	RigidBody::AddVelocity(acceleration * dt);
	RigidBody::Translate(velocity * dt);
}
