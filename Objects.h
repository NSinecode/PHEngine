#pragma once
#include "HitBox.h"
#include <string>
#include "raylib.h"
#include "Addons.h"
#include <vector>

#define	REGULAR	  0
#define	TRIGGERED 1



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
	//~Button();
	
	//Getters and Setters
	void SetButtonHitBox(SimpleHitBox HitBox);
	void SetCenter(Vector2 Center);
	void SetTitle(std::string title);
	void SetWidth(float width);
	void SetHeight(float height);
	void SetWidthAndHeight(float width, float height);
	void SetChoose(bool choose);
	SimpleHitBox GetHitBox();
	Vector2 GetCenter();
	std::vector<Texture2D> GetTexture();
	std::string GetTitle();
	float GetWidth();
	float GetHeight();
	bool GetChoose();
	
	virtual void CheckJob(Vector2 MousePos){};

private:
	bool choose = 0;
	SimpleHitBox HitBox;
	Vector2 Center;
	//Image  texture;
	std::vector<Texture2D> texture;
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