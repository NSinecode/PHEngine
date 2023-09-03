#pragma once
//#include "HitBox.h"
#include <string>
#include "raylib.h"
#include "rlgl.h"
#include "Addons.h"
#include <vector>
#include <unordered_map>

#define	REGULAR	  0
#define	TRIGGERED 1
#define ACTIVE 2





//I use decard's system, so I need to convert
Vector2 TransformPos2CPos(Vector2 pos);
Vector2 TransformPos2CPos(Point pos);

class Button
{
public:
	Button();
	Button(Button& other);
	Button(Vector2 Center, float width, float height);
	Button(Vector2 Center, float width, float height, int FontSize);
	Button(Vector2 Center, float width, float height, std::string title);
	Button(Vector2 Center, float width, float height, std::string title, int FontSize);
	Button(Vector2 Center, float height, std::string title);
	Button(Vector2 Center, float height, std::string title, int FrontSize);

	/*Button(Vector2 Center, float width, float height, Image texture);
	Button(Vector2 Center, float width, float height, Image texture, int mode);
	Button(Vector2 Center, float width, float height, std::string title, Image texture);
	Button(Vector2 Center, float width, float height, std::string title, Image texture, int mode);*/
	~Button();
	
	//Getters and Setters
	void SetAll(Vector2 Center, float height, std::string title);
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
	void DrawButton();
	void DrawButton(int FontSize);

private:
	bool choose = 0;
	SimpleHitBox HitBox;
	Vector2 Center;
	//Image  texture;
	std::vector<Texture2D> texture;
	std::string title;
	float width, height;
	int FontSize = 20;
};


class TriggerButton : public Button
{
public:
	TriggerButton() : Button() {};
	TriggerButton(Vector2 Center, float width, float height) :Button(Center, width, height) {};
	TriggerButton(Vector2 Center, float width, float height, std::string title) :Button(Center, width, height, title) {};
	TriggerButton(Vector2 Center, float height, std::string title) :Button(Center, height, title) {};
	TriggerButton(Vector2 Center, float height, std::string title, int FrontSize) :Button(Center, height, title, FrontSize) {};

	TriggerButton(Button &other);
	

	void CheckJob(Vector2 MousePos, Trigger& other , double Scene);
	
private:
	
};

//class SwitchButton : public Button
//{
//public:
//	SwitchButton() : Button() { GetTexture().push_back(LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), DARKBLUE))); };
//	SwitchButton(Vector2 Center, float width, float height) :Button(Center, width, height) { GetTexture().push_back(LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), DARKBLUE))); };
//	SwitchButton(Vector2 Center, float width, float height, std::string title) :Button(Center, width, height, title) { GetTexture().push_back(LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), DARKBLUE))); };
//	SwitchButton(Vector2 Center, float height, std::string title) :Button(Center, height, title) { GetTexture().push_back(LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), DARKBLUE))); };
//	SwitchButton(Vector2 Center, float height, std::string title, int FrontSize) :Button(Center, height, title, FrontSize) { GetTexture().push_back(LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), DARKBLUE))); };
//
//	//SwitchButton(Button& other);
//
//
//	void CheckJob(Vector2 MousePos);
//
//private:
//	bool IsActive = 1;
//};



//void InitMainButtons(std::unordered_map<std::string, std::vector<Button>>& MainB);

class PhysicsObjRec
{
public:
	PhysicsObjRec();




private:
	PHHitBox HitBox;
	
	float mass, modV, AngleV;

};