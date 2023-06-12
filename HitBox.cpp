#include "HitBox.h"
#include <cmath>

Vector2 RealASin(float sinA)
{
	float A1 = asin(sinA);
	float A2 = PI - A1;

	Vector2 A;
	A.x = A1;
	A.y = A2;

	return A;
}

Vector2 RealACos(float cosA)
{
	float A1 = acos(cosA);
	float A2 = 2*PI - A1;

	Vector2 A;
	A.x = A1;
	A.y = A2;

	return A;
}

float AngleSinCos(float sinA, float cosA)
{
	float Angle;
	if (RealACos(cosA).x == RealASin(sinA).x)
		Angle = RealACos(cosA).x;
	else
		Angle = RealACos(cosA).y;
	return Angle;
}

Point::Point()
{
	Position.x = 0;
	Position.y = 0;
}

Point::Point(Vector2 Position)
{
	this->Position = Position;
}

void Point::SetV(float V)
{
	this->V = V;
}

void Point::SetVcircle(float Vcircle)
{
	this->Vcircle = Vcircle;
}

void Point::SetCenterPosition(Vector2 CenterPosition)
{
	this->CenterPosition = CenterPosition;
}

float Point::GetV()
{
	return V;
}

float Point::GetVcircle()
{
	return Vcircle;
}

Vector2 Point::GetCenterPosition()
{
	return CenterPosition;
}

Point::PhantomPoint::PhantomPoint(Vector2 Position, Vector2 CenterPosition)
{
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
}
