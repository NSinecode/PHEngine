#include "Addons.h"
#include "raylib.h"

Vector2 transformXY2Vec2(float x, float y)
{
	Vector2 aq;
	aq.x = x; aq.y = y;
	return aq;
}

Vector2 TransformPos2CPos(Vector2 pos)
{
    pos.y *= -1;
    return pos;
}

Vector2 TransformPos2CPos(Point pos)
{
    Vector2 a = pos.GetPosition();
    a.y *= -1;
    return a;
}