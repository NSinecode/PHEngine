#pragma once
#include "HitBox.h"
#include "raylib.h"
#include <string>

Vector2 transformXY2Vec2(float x, float y);

//I use decard's system, so I need to convert
Vector2 TransformPos2CPos(Vector2 pos);
Vector2 TransformPos2CPos(Point pos);

void DrawTextB(std::string title, int posX, int posY, int fontSize, Color color);
void DrawTextBV(std::string title, Vector2 pos, int fontSize, Color color);


//In develop
class PHMaterial
{
public:

private:

};

//struct Def
//{
//	Font Default;
//}; 


class Trigger
{
public:
	virtual void Job(){};
};

class SceneSwitcherTrigger
{
public:
	SceneSwitcherTrigger(double Scene0);

	double GetScene();

	void Job(int Scene);
private:
	double Scene = 0;
};
