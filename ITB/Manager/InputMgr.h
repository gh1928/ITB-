#pragma once
#include <list>

//using namespace sf;
using namespace std;

// ����ƽ �Լ��� �̿��ؼ� Ű���� �� ���콺 �Է��� �˻��� �� �ִ� Ŭ����

class InputMgr
{
private:
	static list<int> downList;
	static list<int> ingList;
	static list<int> upList;
	//static Vector2f mousePos;

public:
	static void Init();
	static void Update(float dt);

	//static Vector2f& GetMousePos();
	//static const Vector2f& GetMouseWorldPos();
};

