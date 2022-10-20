#include "InputMgr.h"
#include "../Framework/Framework.h"

list<int> InputMgr::downList;
list<int> InputMgr::ingList;
list<int> InputMgr::upList;

//Vector2f InputMgr::mousePos;

void InputMgr::Init()
{
}

void InputMgr::Update(float dt)
{
	//downList.clear();
	//upList.clear();

	//mousePos = (Vector2f)Mouse::getPosition(FRAMEWORK->GetWindow());
}

//Vector2f& InputMgr::GetMousePos()
//{
//	return mousePos;
//}
//
//const Vector2f& InputMgr::GetMouseWorldPos()
//{
//	RenderWindow& window = FRAMEWORK->GetWindow();
//
//	return window.mapPixelToCoords(Mouse::getPosition(window));
//}

