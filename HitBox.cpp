#include "HitBox.h"
#include <cmath>
#include "raylib.h"
#include <iostream>

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

Point::Point(Point& other)
{
	V = Vcircle = 0;
	this->Position = other.GetPosition();
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

Point::Point(Point& other, Vector2 CenterPosition)
{
	this->CenterPosition = CenterPosition;
	this->Position = other.GetPosition();
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
}

Point::Point(Point& other, Point& CenterPoint)
{
	this->CenterPosition = CenterPoint.GetCenterPosition();
	this->Position = other.GetPosition();
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

void Point::SetX(float X)
{
	Position.x = X;
}

void Point::SetY(float Y)
{
	Position.y = Y;
}

void Point::SetV(float V)
{
	this->V = V;
}

void Point::SetVcircle(float Vcircle)
{
	this->Vcircle = Vcircle;
}

void Point::SetPosition(Vector2 Position)
{
	this->Position = Position;
}

void Point::SetPosition(Point& other)
{
	this->Position = other.GetPosition();
}

void Point::SetCenterPosition(Vector2 CenterPosition)
{
	this->CenterPosition = CenterPosition;
	PhPosition.x = Position.x - CenterPosition.x;
	PhPosition.y = Position.y - CenterPosition.y;
}

void Point::SetCenterPosition(Point& CenterPoint)
{
	this->CenterPosition = CenterPoint.GetCenterPosition();
}

float Point::GetX()
{
	return Position.x;
}

float Point::GetY()
{
	return Position.y;
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
	//Transform from decard's system to Polar system ( from (x,y) to (phi,r) )
	float r = sqrt(pow(PhPosition.x, 2) + pow(PhPosition.y, 2)), sinPHI = PhPosition.y / r, cosPHI = PhPosition.x / r;
	float PHI = AngleSinCos(sinPHI, cosPHI);

	PhPosition.x = cos(PHI + A) * r;
	PhPosition.y = sin(PHI + A) * r;

	Position = TransformPh2Norm();
}

Vector2 Point::TransformPh2Norm()
{
	Vector2 a;
	a.x = PhPosition.x + CenterPosition.x;
	a.y = PhPosition.y + CenterPosition.y;
	return a;
}

SimpleHitBox::SimpleHitBox()
{
	Vector2 a; 
	a.x = a.y = 0;
	MinXMinY.SetPosition(a);
	MaxXMaxY.SetPosition(a);
	Center = a;
}

SimpleHitBox::SimpleHitBox(Point MinXMinY, Point MaxXMaxY)
{
	this->MinXMinY.SetPosition(MinXMinY.GetPosition());
	this->MaxXMaxY.SetPosition(MaxXMaxY.GetPosition());
	width = MaxXMaxY.GetPosition().x - MinXMinY.GetPosition().x;
	height = MaxXMaxY.GetPosition().y - MinXMinY.GetPosition().y;
	Vector2 a;
	a.x = MinXMinY.GetPosition().x + width / 2;
	a.y = MinXMinY.GetPosition().y + height / 2;
	Center = a;
}

SimpleHitBox::SimpleHitBox(Point MinXMinY, Vector2 Center)
{
	this->MinXMinY.SetPosition(MinXMinY.GetPosition());
	this->Center = Center;
	width = (Center.x - MinXMinY.GetPosition().x) * 2;
	height = (Center.y - MinXMinY.GetPosition().y) * 2;
	Vector2 a;
	a.x = Center.x + width / 2;
	a.y = Center.y + height / 2;
	MaxXMaxY.SetPosition(a);
}

SimpleHitBox::SimpleHitBox(Vector2 Center, Point MaxXMaxY)
{
	this->MaxXMaxY.SetPosition(MaxXMaxY.GetPosition());
	this->Center = Center;
	width = (-Center.x + MaxXMaxY.GetPosition().x) * 2;
	height = (-Center.y + MaxXMaxY.GetPosition().y) * 2;
	Vector2 a;
	a.x = Center.x - width / 2;
	a.y = Center.y - height / 2;
	MinXMinY.SetPosition(a);
}

SimpleHitBox::SimpleHitBox(Vector2 Center, float width, float height)
{
	/*try
	{
		if (width)
			this->width = width;
		throw "width = 0";
	}
	catch(...)
	{
		std::cout << "ERROR" << std::endl;
	}
	try
	{
		if (height)
			this->width = height;
		throw "height = 0";
	}
	catch (...)
	{
		std::cout << "ERROR" << std::endl;
	}*/
	this->Center = Center;
	this->width = width;
	this->height = height;
	Vector2 a, b;
	a.x = Center.x - width / 2;
	a.y = Center.y - height / 2;
	b.x = Center.x + width / 2;
	b.y = Center.y + height / 2;
	MinXMinY.SetPosition(a);
	MaxXMaxY.SetPosition(b);
}

void SimpleHitBox::SetMinXMinY(Point MinXMinY)
{
	this->MinXMinY = MinXMinY;
}

void SimpleHitBox::SetMaxXMaxY(Point MaxXMaxY)
{
	this->MaxXMaxY = MaxXMaxY;
}

void SimpleHitBox::SetCenter(Vector2 Center)
{
	this->Center = Center;
	Vector2 a, b;
	a.x = Center.x - width / 2;
	a.y = Center.y - height / 2;
	b.x = Center.x + width / 2;
	b.y = Center.y + height / 2;
	MinXMinY.SetPosition(a);
	MaxXMaxY.SetPosition(b);
}

void SimpleHitBox::SetCenterN(Vector2 Center)
{
	this->Center = Center;
}

void SimpleHitBox::SetHeight(float height)
{
	this->height = height;
}

void SimpleHitBox::SetWidth(float width)
{
	this->width = width;
}

Point SimpleHitBox::GetMinXMinY()
{
	return MinXMinY;
}

Point SimpleHitBox::GetMaxXMaxY()
{
	return MaxXMaxY;
}

Vector2 SimpleHitBox::GetCenter()
{
	return Center;
}

bool SimpleHitBox::CheckMouse(Vector2 MousePos)
{
	if ((MinXMinY.GetPosition().x <= MousePos.x && MousePos.x <= MaxXMaxY.GetPosition().x) && (MinXMinY.GetPosition().y <= MousePos.y && MousePos.y <= MaxXMaxY.GetPosition().y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

Point PHHitBox::GetMinXMaxY()
{
	return MinXMaxY;
}

Point PHHitBox::GetMaxXMinY()
{
	return MaxXMinY;
}

void PHHitBox::Resize(Vector2 Delta)
{
	GetMaxXMaxY().SetX(GetMaxXMaxY().GetX() + Delta.x / 2);
	MaxXMinY.SetX(MaxXMinY.GetX() + Delta.x / 2);

	GetMinXMinY().SetX(GetMinXMinY().GetX() - Delta.x / 2);
	MinXMaxY.SetX(MinXMaxY.GetX() - Delta.x / 2);

	SetWidth(GetMaxXMaxY().GetX() - GetMinXMinY().GetX());

	GetMaxXMaxY().SetY(GetMaxXMaxY().GetY() + Delta.y / 2);
	MinXMaxY.SetY(MinXMaxY.GetY() + Delta.y / 2);

	GetMinXMinY().SetY(GetMaxXMaxY().GetY() - Delta.y / 2);
	MaxXMinY.SetY(MaxXMinY.GetY() - Delta.y / 2);

	SetHeight(GetMaxXMaxY().GetY() - GetMinXMinY().GetY());
}

void PHHitBox::ResizeWIDTH(float DeltaWIDTH)
{
	GetMaxXMaxY().SetX(GetMaxXMaxY().GetX() + DeltaWIDTH / 2);
	MaxXMinY.SetX(MaxXMinY.GetX() + DeltaWIDTH / 2);

	GetMinXMinY().SetX(GetMinXMinY().GetX() - DeltaWIDTH / 2);
	MinXMaxY.SetX(MinXMaxY.GetX() - DeltaWIDTH / 2);

	SetWidth(GetMaxXMaxY().GetX() - GetMinXMinY().GetX());
}

void PHHitBox::ResizeHEIGHT(float DeltaHEIGHT)
{
	GetMaxXMaxY().SetY(GetMaxXMaxY().GetY() + DeltaHEIGHT / 2);
	MinXMaxY.SetY(MinXMaxY.GetY() + DeltaHEIGHT / 2);

	GetMinXMinY().SetY(GetMaxXMaxY().GetY() - DeltaHEIGHT / 2);
	MaxXMinY.SetY(MaxXMinY.GetY() - DeltaHEIGHT / 2);

	SetHeight(GetMaxXMaxY().GetY() - GetMinXMinY().GetY());
}

void PHHitBox::Move(float xd, float yd)
{
	SetCenterN({ xd,yd });

	GetMinXMinY().SetPosition({ GetMinXMinY().GetX() + xd, GetMinXMinY().GetY() + yd });
	GetMaxXMaxY().SetPosition({ GetMaxXMaxY().GetX() + xd, GetMaxXMaxY().GetY() + yd });

	MinXMaxY.SetPosition({ MinXMaxY.GetX() + xd, MinXMaxY.GetY() + yd });
	MaxXMinY.SetPosition({ MaxXMinY.GetX() + xd, MaxXMinY.GetY() + yd });
}

void PHHitBox::Move(Vector2 posd)
{
	float xd = posd.x, yd = posd.y;
	SetCenterN({ xd,yd });

	GetMinXMinY().SetPosition({ GetMinXMinY().GetX() + xd, GetMinXMinY().GetY() + yd });
	GetMaxXMaxY().SetPosition({ GetMaxXMaxY().GetX() + xd, GetMaxXMaxY().GetY() + yd });

	MinXMaxY.SetPosition({ MinXMaxY.GetX() + xd, MinXMaxY.GetY() + yd });
	MaxXMinY.SetPosition({ MaxXMinY.GetX() + xd, MaxXMinY.GetY() + yd });
}

void PHHitBox::RotateAroundPoint(float Angle, Point CenterOfRotation)
{
	MinXMaxY.RotateAroundCenter(CenterOfRotation.GetPosition(), Angle);
	MaxXMinY.RotateAroundCenter(CenterOfRotation.GetPosition(), Angle);
	GetMinXMinY().RotateAroundCenter(CenterOfRotation.GetPosition(), Angle);
	GetMaxXMaxY().RotateAroundCenter(CenterOfRotation.GetPosition(), Angle);
}

void PHHitBox::RotateAroundCenter(float Angle)
{
	MinXMaxY.RotateAroundCenter(GetCenter(), Angle);
	MaxXMinY.RotateAroundCenter(GetCenter(), Angle);
	GetMinXMinY().RotateAroundCenter(GetCenter(), Angle);
	GetMaxXMaxY().RotateAroundCenter(GetCenter(), Angle);
}
