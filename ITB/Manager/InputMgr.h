#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>

using namespace sf;
using namespace std;

// 스택틱 함수를 이용해서 키보드 및 마우스 입력을 검사할 수 있는 클래스

class InputMgr
{
private:

	static list<int> downList;
	static list<int> ingList;
	static list<int> upList;

	static Vector2f mousePos;

public:
	static void Init();
	static void Update(float dt);
	static void ProcessInput(Event& ev);

	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);

	static const Vector2f& GetMousePos();
	static bool GetMouseButtonDown(Mouse::Button key);
	static bool GetMouseButton(Mouse::Button key);
	static bool GetMouseButtonUp(Mouse::Button key);

};
