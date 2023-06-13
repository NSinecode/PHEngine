#pragma once 
#include "raylib.h"
//#include "HitBox.cpp"
#include <string>
#include <cmath>

//cmath overdrives
float pow(const float num, int exp);

//About Angles
Vector2 RealASin(float sinA);
Vector2 RealACos(float cosA);
float AngleSinCos(float sinA, float cosA);

class Point
{
public:
	Point();
	Point(Vector2 Position);
	Point(Vector2 Position, Vector2 CenterPosition);

	//Setters and Getters
	void SetV(float V);
	void SetVcircle(float Vcircle);
	void SetCenterPosition(Vector2 CenterPosition);
	float GetV();
	float GetVcircle();
	Vector2 GetPosition();
	Vector2 GetCenterPosition();
	Vector2 GetPhPosition();

	void RotateAroundCenter(float A);
	void RotateAroundCenter(Vector2 CenterPosition, float A);

	Vector2 TransformPh2Norm();


private:
	float V, Vcircle;
	Vector2 Position, CenterPosition, PhPosition;
};
