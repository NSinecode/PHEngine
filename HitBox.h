#pragma once 
#include "raylib.h"
#include <cmath>

//cmath overdrives
float pow(const float num, int exp);

//About Angles
Vector2 RealASin(float sinA);
Vector2 RealACos(float cosA);
float AngleSinCos(float sinA, float cosA);

//Just basic class for hitbox
class Point
{
public:
	Point();
	Point(Point &other);
	Point(Vector2 Position);
	Point(Point &other, Vector2 CenterPosition);
	Point(Point& other, Point& CenterPoint);
	Point(Vector2 Position, Vector2 CenterPosition);

	//Setters and Getters
	void SetV(float V);
	void SetVcircle(float Vcircle);
	void SetPosition(Vector2 Position);
	void SetPosition(Point& other);
	void SetCenterPosition(Vector2 CenterPosition);
	void SetCenterPosition(Point& CenterPoint);
	float GetV();
	float GetVcircle();
	Vector2 GetPosition();
	Vector2 GetCenterPosition();
	Vector2 GetPhPosition();

	//About rotate
	void RotateAroundCenter(float A);
	void RotateAroundCenter(Vector2 CenterPosition, float A);

	Vector2 TransformPh2Norm();

private:
	float V, Vcircle;
	Vector2 Position, CenterPosition, PhPosition; // PhPosition = Phantom position
};

class SimpleHitBox
{
public:
	SimpleHitBox();
	SimpleHitBox(Point MinXMinY, Point MaxXMaxY);
	SimpleHitBox(Point MinXMinY, Vector2 Center);
	SimpleHitBox(Vector2 Center, Point MaxXMaxY);
	SimpleHitBox(Vector2 Center, float width, float height);

	//Setters and Getters 
	void SetMinXMinY(Point MinXMinY);
	void SetMaxXMaxY(Point MaxXMaxY);
	void SetCenter(Vector2 Center);
	Point GetMinXMinY();
	Point GetMaxXMaxY();
	Vector2 GetCenter();

	bool CheckMouse(Vector2 MousePos);

private:
	Point MinXMinY, MaxXMaxY;
	Vector2 Center;
};
