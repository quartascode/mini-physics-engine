#include "physics.hpp"
#include "rigidbody.hpp"
#include "vec2.hpp"
#include <algorithm>
#include <cmath>

void Physics::BorderCollision(RigidBody& rb, const Vec2& size) {
	float halfWidth = size.x / 2.0;
	float halfHeight = size.y / 2.0;

	Vec2 pos = rb.Position();
	Vec2 vel = rb.Velocity();
	float rest = rb.Restitution();
	bool collided = false;

	if (pos.x >= worldBounds.right - halfWidth) {
		pos.x = worldBounds.right - halfWidth;
		vel.x = -vel.x * rest;
		collided = true;
	}
	if (pos.x <= worldBounds.left + halfWidth) {
		pos.x = worldBounds.left + halfWidth;
		vel.x = -vel.x * rest;
		collided = true;
	}
	if (pos.y>= worldBounds.up - halfHeight) {
		pos.y = worldBounds.up - halfHeight;
		vel.y = -vel.y * rest;
		collided = true;
	}
	if (pos.y <= worldBounds.down + halfHeight) {
		pos.y = worldBounds.down + halfHeight;
		vel.y = -vel.y * rest;
		collided = true;
	}

	if (collided) {
		rb.SetPosition(pos);
		rb.SetVelocity(vel);
	}
}

void Physics::BoxCollision(Box& a, Box& b) {
	RigidBody& rba = a.GetRigidBody();
	RigidBody& rbb = b.GetRigidBody();
	Vec2 posa = rba.Position();
	Vec2 posb = rbb.Position();
	Vec2 sizea = a.Size();
	Vec2 sizeb = b.Size();

	// four edges
	float lea = posa.x - sizea.x / 2;
	float rea = posa.x + sizea.x / 2;
	float uea = posa.y + sizea.y / 2;
	float dea = posa.y - sizea.y / 2;

	float leb = posb.x - sizeb.x / 2;
	float reb = posb.x + sizeb.x / 2;
	float ueb = posb.y + sizeb.y / 2;
	float deb = posb.y - sizeb.y / 2;

	if (lea <= reb && rea >= leb && uea >= deb && dea <= ueb) {
		Vec2 vela = rba.Velocity();
		Vec2 velb = rbb.Velocity();
		float resta = rba.Restitution();
		float restb = rbb.Restitution();
		float massa = rba.Mass();
		float massb = rbb.Mass();

		float e = std::sqrt(resta * restb);

		float overlapLeft = rea - leb;
		float overlapRight = reb - lea;
		float overlapUp = uea - deb;
		float overlapDown = ueb - dea;

		float overlapX = std::min(overlapLeft, overlapRight);
		float overlapY = std::min(overlapUp, overlapDown);
		
		if (overlapX <= overlapY) {
			// lateral collision
			float vrel = vela.x - velb.x;
			float j = -(1 + e) * vrel / (1/massa + 1/massb);
			float velaf = vela.x + j / massa;
			float velbf = velb.x - j / massb;
			if (posa.x < posb.x) {
				// a to the left of b
				rba.Translate({-overlapX / 2, 0});
				rbb.Translate({ overlapX / 2, 0});

			} else {
				rba.Translate({ overlapX / 2, 0});
				rbb.Translate({-overlapX / 2, 0});
			}
			vela.x = velaf;
			velb.x = velbf;
		} else {
			float vrel = vela.y - velb.y;
			float j = -(1 + e) * vrel / (1/massa + 1/massb);
			float velaf = vela.y + j / massa;
			float velbf = velb.y - j / massb;
			if (posa.y < posb.y) {
				// a down b up
				rba.Translate({0, -overlapY / 2});
				rbb.Translate({0,  overlapY / 2});
			} else {
				rba.Translate({0,  overlapY / 2});
				rbb.Translate({0, -overlapY / 2});
			}
			vela.y = velaf;
			velb.y = velbf;
		}
		rba.SetVelocity(vela);
		rbb.SetVelocity(velb);
	}
}
