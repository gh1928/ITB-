#include "InputMgr.h"
#include <iostream>
#include <algorithm>
#include "../Framework/Framework.h"

list<int> InputMgr::downList;
list<int> InputMgr::ingList;
list<int> InputMgr::upList;

Vector2f InputMgr::mousePos;

void InputMgr::Init()
{
}

void InputMgr::Update(float dt)
{
	downList.clear();
	upList.clear();

	mousePos = (Vector2f)Mouse::getPosition(FRAMEWORK->GetWindow());
}

void InputMgr::ProcessInput(Event& ev)
{
	switch (ev.type)
	{
	case Event::EventType::MouseButtonPressed:
	{
		int code = ev.mouseButton.button + Keyboard::KeyCount;
		if (find(ingList.begin(), ingList.end(), code) == ingList.end())
		{
			downList.push_back(code);
			ingList.push_back(code);
		}
	}
	break;
	case Event::EventType::MouseButtonReleased:
	{
		int code = ev.mouseButton.button + Keyboard::KeyCount;

		ingList.remove(code);
		upList.push_back(code);
	}
	break;
	case Event::EventType::KeyPressed:
		if (find(ingList.begin(), ingList.end(), ev.key.code) == ingList.end())
		{
			downList.push_back(ev.key.code);
			ingList.push_back(ev.key.code);
		}
		break;
	case Event::EventType::KeyReleased:
		ingList.remove(ev.key.code);
		upList.push_back(ev.key.code);
		break;
	}
}

bool InputMgr::GetKeyDown(Keyboard::Key key)
{
	return find(downList.begin(), downList.end(), key) != downList.end();
}

bool InputMgr::GetKey(Keyboard::Key key)
{
	return find(ingList.begin(), ingList.end(), key) != ingList.end();
}

bool InputMgr::GetKeyUp(Keyboard::Key key)
{
	return find(upList.begin(), upList.end(), key) != upList.end();
}

const Vector2f& InputMgr::GetMousePos()
{
	return mousePos;
}

bool InputMgr::GetMouseButtonDown(Mouse::Button key)
{
	int code = key + Keyboard::KeyCount;
	return find(downList.begin(), downList.end(), code) != downList.end();
}

bool InputMgr::GetMouseButton(Mouse::Button key)
{
	int code = key + Keyboard::KeyCount;
	return find(ingList.begin(), ingList.end(), code) != ingList.end();
}

bool InputMgr::GetMouseButtonUp(Mouse::Button key)
{
	int code = key + Keyboard::KeyCount;
	return find(upList.begin(), upList.end(), code) != upList.end();
}
