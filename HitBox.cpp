#include "HitBox.h"
#include <cmath>
#include "raylib.h"

float pow(const float num, int exp)
{
	float a=1;
	for (int i = 0; i <= exp; i++)
	{
		a *= num;
	}
	return a;
}

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
	V = Vcircle = 0;
	Position.x = 0;
	Position.y = 0;
	CenterPosition.x = 0;
	CenterPosition.y = 0;
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
}

Point::Point(Vector2 Position)
{
	V = Vcircle = 0;
	this->Position = Position;
	CenterPosition.x = 0;
	CenterPosition.y = 0;
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
}

Point::Point(Vector2 Position, Vector2 CenterPosition)
{
	V = Vcircle = 0;
	this->CenterPosition = CenterPosition;
	this->Position = Position;
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
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
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
}

float Point::GetV()
{
	return V;
}

float Point::GetVcircle()
{
	return Vcircle;
}

Vector2 Point::GetPosition()
{
	return Position;
}

Vector2 Point::GetCenterPosition()
{
	return CenterPosition;
}

Vector2 Point::GetPhPosition()
{
	return PhPosition;
}

void Point::RotateAroundCenter(float A)
{
	//Transform from decard's system to Polar system ( from (x,y) to (phi,r) )
	float r = sqrt(pow(PhPosition.x,2) + pow(PhPosition.y, 2)), sinPHI =PhPosition.y / r, cosPHI = PhPosition.x / r;
	float PHI = AngleSinCos(sinPHI, cosPHI);

	PhPosition.x = cos(PHI + A) * r;
	PhPosition.y = sin(PHI + A) * r;

	Position = TransformPh2Norm();
}

void Point::RotateAroundCenter(Vector2 CenterPosition, float A)
{
	SetCenterPosition(CenterPosition);
	float r = sqrt(pow(PhPosition.x, 2) + pow(PhPosition.y, 2)), sinA = PhPosition.y / r, cosA = PhPosition.x / r;

}

Vector2 Point::TransformPh2Norm()
{
	Vector2 a;
	a.x = PhPosition.x + CenterPosition.x;
	a.y = PhPosition.y + CenterPosition.y;
	return a;
}
