#pragma once
#include "HitBox.h"
#include <string>
#include "raylib.h"
#include "Addons.h"

//using namespace std;

//I use decard's system, so I need to convert
Vector2 TransformPos2CPos(Vector2 pos);
Vector2 TransformPos2CPos(Point pos);

class Button
{
public:
	Button();
	Button(Vector2 Center, float width, float height);
	Button(Vector2 Center, float width, float height, int mode);
	Button(Vector2 Center, float width, float height, std::string title);
	Button(Vector2 Center, float width, float height, std::string title, int mode);
	/*Button(Vector2 Center, float width, float height, Image texture);
	Button(Vector2 Center, float width, float height, Image texture, int mode);
	Button(Vector2 Center, float width, float height, std::string title, Image texture);
	Button(Vector2 Center, float width, float height, std::string title, Image texture, int mode);*/
	~Button();
	
	//Getters and Setters
	void SetButtonHitBox(SimpleHitBox HitBox);
	void SetCenter(Vector2 Center);
	void SetTexture(Image texture);
	void SetTitle(std::string title);
	void SetWidth(float width);
	void SetHeight(float height);
	void SetWidthAndHeight(float width, float height);
	void SetMode(int mode);
	SimpleHitBox GetHitBox();
	Vector2 GetCenter();
	Image GetTexture();
	std::string GetTitle();
	float GetWidth();
	float GetHeight();
	int GetMode();
	
	virtual void CheckJob(Vector2 MousePos){};

private:
	SimpleHitBox HitBox;
	Vector2 Center;
	Image  texture;
	std::string title;
	float width, height;
	int mode;
};


class TriggerButton : public Button
{
public:
	TriggerButton(Vector2 Center, float width, float height) :Button(Center, width, height) {};
	TriggerButton(Vector2 Center, float width, float height, std::string title) :Button(Center, width, height, title) {};

	void CheckJob(Vector2 MousePos, Trigger& other);	//it isn't working
private:
	int count = 0;
};