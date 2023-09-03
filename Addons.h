#pragma once
#include "HitBox.h"
#include "raylib.h"
//#include "Scene.h"
#include <string>
#include <vector>
//#include "Objects.h"


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

class Sell
{
public:
	Sell();
	Sell(Vector2 Center);
	Sell(Vector2 Center, bool alive);

	//void SetCenter();
	void Setalive(bool alive);
	Vector2 GetCenter();
	bool Getalive();

private:
	Vector2 Center;
	bool alive;
};

int CountNeighbours(std::vector<std::vector<Sell>> LifeHeight, int i, int j);


class Trigger 
{
public:
	virtual void Job(double Scene0){};
};

class SceneSwitcherTrigger : public Trigger
{
public:
	SceneSwitcherTrigger();
	SceneSwitcherTrigger(double Scene0);

	double GetScene();

	void Job(double Scene);
private:
	double Scene = 0;
};

//class SwitcherTrigger : public Trigger
//{
//public:
//	SwitcherTrigger();
//	SwitcherTrigger(bool IsActive);
//
//	bool GetActive();
//
//	void Job();
//private:
//	bool IsActive;
//}
