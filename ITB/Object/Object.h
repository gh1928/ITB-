#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Object
{
protected:
	bool enabled;

	Vector2f position;
public:
	Object();
	virtual ~Object();

	virtual void SetActive(bool active) { enabled = active; }
	virtual bool GetActive() const { return enabled; }

	virtual void Init() { Reset(); }
	virtual void Release();

	virtual void Reset() { enabled = true; }

	virtual void SetPos(const Vector2f& pos) { position = pos; }
	virtual void Translate(const Vector2f& delta);

	virtual const Vector2f& GetPos() const { return position; }

	virtual void Update(float dt) = 0;
	virtual void Draw(RenderWindow& window) = 0;
};

