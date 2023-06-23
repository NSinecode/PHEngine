#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "HitBox.h"
#include "Objects.h"
#include "Addons.h"

#define	MAINMENU	0

#define	SETTINGS	0.1

#define WORKSHOP	0.2

#define CREDITS		0.3



void MainScene(SceneSwitcherTrigger trigger, std::vector<std::vector<Sell>> &LifeHeight, int count, Texture2D Sells, int &lifecount);