#include "vec2.hpp"
#include "world.hpp"

class RigidBody {
	public:
		RigidBody(Vec2 position, float mass, float restitution)
			: position(position),
			velocity({0, 0}),
			acceleration({0, -9.81}),
			resultantForce({0, 0}),
			mass(mass),
			inverseMass(1.0 / mass),
			restitution(restitution)
			{}

		const Vec2& Position() const { return position; }

		void SetPosition(const Vec2& pos) { position = pos; }

		void SetVelocity(const Vec2& vel) { velocity = vel; }

		void AddVelocity(const Vec2& vel) { velocity += vel; }

		void Translate(const Vec2& v) { position += v; }

		void UpdateMovement(float dt);

		void BorderCollision(const WorldBounds& bounds, const Vec2& size);

	private:
		Vec2 position;
		Vec2 velocity;
		Vec2 acceleration;
		Vec2 resultantForce;

		float mass;
		float inverseMass;
		float restitution;
};
