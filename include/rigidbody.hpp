#include "vec2.hpp"

class RigidBody {
	public:
		RigidBody(Vec2 position, float mass, float restitution)
			: position(position),
			mass(mass),
			restitution(restitution)
			{}
	private:
		Vec2 position;
		Vec2 velocity;
		Vec2 acceleration;

		float mass;
		float restitution;
};
