#pragma once
#include "HitBox.h"
#include "raylib.h"

Vector2 transformXY2Vec2(float x, float y);

//I use decard's system, so I need to convert
Vector2 TransformPos2CPos(Vector2 pos);
Vector2 TransformPos2CPos(Point pos);

//In develop
class PHMaterial
{
public:

private:

};

class Trigger
{
public:
	virtual void Job(){};
};
