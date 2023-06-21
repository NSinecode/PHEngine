#include "Addons.h"
#include "raylib.h"
//#include "PHEngine.cpp"




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

//void DrawTextB(std::string title, int posX, int posY, int fontSize, Color color)
//{
//    DrawTextEx( FontDef.Default, title.c_str(), { (float)posX , (float)posY }, fontSize, 1, color );
//}
//
//void DrawTextBV(std::string title, Vector2 pos, int fontSize, Color color)
//{
//    DrawTextEx( FontDef.Default, title.c_str(), pos, fontSize, 1, color );
//}

SceneSwitcherTrigger::SceneSwitcherTrigger(double Scene0)
{
    Scene = Scene0;
}

double SceneSwitcherTrigger::GetScene()
{
    return Scene;
}

void SceneSwitcherTrigger::Job(int Scene)
{
    this->Scene = Scene;
}
