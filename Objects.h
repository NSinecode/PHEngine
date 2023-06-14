#pragma once
#include "HitBox.h"
#include <string>
#include "raylib.h"

//using namespace std;

//I use decard's system, so I need to convert
Vector2 TransformPos2CPos(Vector2 pos);
Vector2 TransformPos2CPos(Point pos);

class Button
{
public:
	Button();
	Button(Vector2 Center, float width, float height);
	Button(Vector2 Center, float width, float height, std::string title);
	Button(Vector2 Center, float width, float height, Image texture);
	Button(Vector2 Center, float width, float height, std::string title, Image texture);

	//Getters and Setters
	void SetButtonHitBox(SimpleHitBox HitBox);
	void SetCenter(Vector2 Center);
	void SetTexture(Image texture);
	void SetTitle(std::string title);
	void SetWidth(float width);
	void SetHeight(float height);
	void SetWidthAndHeight(float width, float height);
	SimpleHitBox GetHitBox();
	Vector2 GetCenter();
	Image GetTexture();
	std::string GetTitle();
	float GetWidth();
	float GetHeight();
	
private:
	SimpleHitBox HitBox;
	Vector2 Center;
	Image texture;
	std::string title;
	float width, height;
};
