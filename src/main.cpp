#include "raylib.h"


struct Vec2 {
	float x;
	float y;

	Vec2 operator+(const Vec2& v) const {
		return {x + v.x, y + v.y};
	}
	Vec2 operator-(const Vec2& v) const {
		return {x - v.x, y - v.y};
	}
	Vec2 operator*(const Vec2& v) const {
		return {x * v.x, y * v.y};
	}
	Vec2 operator*(const float k) const {
		return {x * k, y * k};
	}
	Vec2& operator+=(const Vec2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
};	

class SimCamera {
	public:
		SimCamera(Vec2 position, float zoom, int screenWidth, int screenHeight)
			: position(position),
			  zoom(zoom),
			  screenWidth(screenWidth),
			  screenHeight(screenHeight)
		{
			InitWindow(screenWidth, screenHeight, "engine");
			SetTargetFPS(60);
		}

		Vec2 WorldToScreen(const Vec2& v) const {
			float screenX =  (v.x - position.x) * zoom + screenWidth / 2.0f;
			float screenY = -(v.y + position.y) * zoom + screenHeight / 2.0f;
			return {screenX, screenY};
		}

		float WorldToScreen(float length) const {
			return length * zoom;
		}

		int GetScreenWidth() const { return screenWidth; }

		int GetScreenHeight() const { return screenHeight; }

		float GetZoom() const { return zoom; }

	private:
		Vec2 position;
		float zoom;
		int screenWidth;
		int screenHeight;
};

struct WorldBounds {
	WorldBounds(const SimCamera& cam) {
		right = cam.GetScreenWidth() / (cam.GetZoom() * 2);
		left = -right;
		up = cam.GetScreenHeight() / (cam.GetZoom() * 2);
		down = -up;
	}

	float left;
	float down;
	float up;
	float right;
};

class Box {
	public:
		Box(Vec2 position, float width, float height, float mass)
			: position(position),
			size({width, height}),
			velocity({20, 0}),
			acceleration({0, -9.81}),
			restitution(0.1),
			mass(mass)
		{}

		const Vec2& GetPosition() const { return position; }

		const Vec2& GetSize() const { return size; }

		void UpdateMovement(float dt) {
			velocity += acceleration * dt;
			position += velocity * dt;
		}

		void BorderCollision(const WorldBounds& bounds){
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
			
	private:
		Vec2 position;
		Vec2 size;
		Vec2 velocity;
		Vec2 acceleration;
		float restitution;
		float mass;
};

class Renderer {
	public:
		void Render(const Box& box, const SimCamera& cam) {
			BeginDrawing();
				ClearBackground(BLACK);
				Vec2 topLeft = box.GetPosition() - (Vec2){box.GetSize().x * 0.5f, box.GetSize().y * -0.5f};
				DrawRectangle(cam.WorldToScreen(topLeft).x, cam.WorldToScreen(topLeft).y, cam.WorldToScreen(box.GetSize().x), cam.WorldToScreen(box.GetSize().y), BLUE);
			EndDrawing();
		}
	private:

};


int main() {
	SimCamera cam({0, 0}, 80.0f, 800, 600);

	WorldBounds bounds(cam);

	Renderer renderer;

	Box box({0, 0}, 0.5, 0.5, 20);

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();
		box.UpdateMovement(dt);
		box.BorderCollision(bounds);

		renderer.Render(box, cam);
	}
}
