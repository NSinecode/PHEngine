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

int CountNeighbours(std::vector<std::vector<Sell>> LifeHeight, int i, int j)
{
    int a = 0, e = i - 1, r;
    for (int q = 0; q <= 2; q++)
    {
        if (e < 0)
            e = LifeHeight.size() - 1;
        if (e == LifeHeight.size())
            e = 0;
        r = j - 1 + q;
        for (int w = 0; w <= 2; w++)
        {
            if (r < 0)
                r = LifeHeight[q].size() - 1;
            if (r == LifeHeight[q].size())
                r = 0;
            if(!(e == i && r == j))
                a += LifeHeight[e][r].Getalive();
            r++;
        }
        e++;
    }
    return a;
}

//std::vector<TriggerButton> InitMainMenuButtons()
//{
//    std::vector<TriggerButton> a;
//
//    TriggerButton start({ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, GetScreenWidth() / 50, GetScreenHeight() / 20, LoadFileText("/Localization/en.txt"));
//    a.push_back(start);
//    
//    return a;
//}

//void DrawTextB(std::string title, int posX, int posY, int fontSize, Color color)
//{
//    DrawTextEx( FontDef.Default, title.c_str(), { (float)posX , (float)posY }, fontSize, 1, color );
//}
//
//void DrawTextBV(std::string title, Vector2 pos, int fontSize, Color color)
//{
//    DrawTextEx( FontDef.Default, title.c_str(), pos, fontSize, 1, color );
//}

SceneSwitcherTrigger::SceneSwitcherTrigger()
{
    Scene = 0;
}

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

Sell::Sell()
{
    Center = { 5,5 };
}

Sell::Sell(Vector2 Center)
{
    this->Center = Center;
}

Sell::Sell(Vector2 Center, bool alive)
{
    this->Center = Center;
    this->alive = alive;
}

void Sell::Setalive(bool alive)
{
    this->alive = alive;
}

Vector2 Sell::GetCenter()
{
    return Center;
}

bool Sell::Getalive()
{
    return alive;
}
