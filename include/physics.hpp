#include "world.hpp"
#include "rigidbody.hpp"

class Physics {
	public:
		Physics(WorldBounds& bounds)
			: gravityAccel({0, -9.81}),
			worldBounds(bounds)
		{}

		void UpdateMovement(RigidBody& rb, float dt);

		void BorderCollision(RigidBody rb, const WorldBounds& bounds, const Vec2& size);

	private:
		Vec2 gravityAccel;
		WorldBounds worldBounds;
};
