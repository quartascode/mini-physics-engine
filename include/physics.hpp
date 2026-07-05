#include "world.hpp"

class Physics {
	public:
		Physics(WorldBounds& bounds)
			: gravityAccel({0, -9.81}),
			worldBounds(bounds)
		{}
	private:
		Vec2 gravityAccel;
		WorldBounds worldBounds;
};
