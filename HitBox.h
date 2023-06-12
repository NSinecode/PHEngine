#pragma once 
#include "raylib.h"
#include "HitBox.cpp"
#include <string>
#include <cmath>


//About Angles
Vector2 RealASin(float sinA);
Vector2 RealACos(float cosA);
float AngleSinCos(float sinA, float cosA);

class Point
{
public:
	Point();
	Point(Vector2 Position);

	//Setters and Getters
	void SetV(float V);
	void SetVcircle(float Vcircle);
	void SetCenterPosition(Vector2 CenterPosition);
	float GetV();
	float GetVcircle();
	Vector2 GetCenterPosition();

private:

	// For rotation around center
	class PhantomPoint
	{
	public:
		Vector2 PhPosition;

		PhantomPoint(Vector2 Position, Vector2 CenterPosition);
	};

	float V, Vcircle;
	Vector2 Position, CenterPosition;
};
