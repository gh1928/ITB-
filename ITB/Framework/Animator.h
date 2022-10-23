#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "EnumClasses.h"

using namespace sf;
using namespace std;

class SpriteObj;
class Animator
{
protected:
	SpriteObj* spriteObj;
	Sprite* sprite;

	AnimationType type;
	Texture* texture;
	IntRect rectSourceSprite;
	Vector2f origin;

	int rowNum;
	int columnNum;

	bool loop;
	bool stop;

	float timer;
	float playTime;

public:
	Animator();
	~Animator();
public:
	//������ �� ��������Ʈ �Լ��� �� ����������
	void SetSpriteObj(SpriteObj* spriteObj, AnimationType type);
	void SetOrigin(Vector2f origin);
	void SetEndTime(float timer);
	void SetTexture(string id, int rowNum, int columnNum = 1, int posx = 0, int posy = 0);	
	void SetLoop(bool loop);
	void ResetAnimaion();	
	void UpdateAnimation(float dt);	
	bool FrameCheck(int n);
	void Stop();
	void Play();
};