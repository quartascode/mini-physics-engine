#include "world.hpp"
#include "rigidbody.hpp"
#include "box.hpp"

class Physics {
	public:
		Physics(WorldBounds& bounds)
			: gravityAccel({0, -9.81}),
			worldBounds(bounds)
		{}

		void BorderCollision(RigidBody& rb, const Vec2& size);

		void BoxCollision(Box& a, Box& b);

	private:
		Vec2 gravityAccel;
		WorldBounds worldBounds;
};
