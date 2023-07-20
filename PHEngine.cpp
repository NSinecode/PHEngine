#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "HitBox.h"
#include "Objects.h"
#include "Addons.h"
#include "Scene.h"


int main()
{
    
    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());

    InitWindow(screenWidth, screenHeight, "PHEngine");

    SetWindowPosition(0, 30);

    Texture Sells = LoadTextureFromImage(GenImageColor(30, 30, WHITE));

    std::vector<std::vector<Sell>> LifeHeight;
    LifeHeight.reserve(192);
    

    for (int i = 0; i < GetScreenWidth() / 30; i++)
    {
        std::vector<Sell> q;
        q.reserve(108);
        for (int j = 0; j < GetScreenHeight() / 30; j++)
        {
            Sell a({ (float)5 + 30*i, (float)5 + 30*j }, GetRandomValue(0,1));
            q.push_back(a);
        }
        LifeHeight.push_back(q);
    }

    int maincount = 0, lifecount = 0;
    //std::vector<Button> Main = InitMainMenuButtons();

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    SceneSwitcherTrigger MAINTRIGGER;

    while (!WindowShouldClose())        
    {
        //Just main menu, i will complete it later
        if (MAINTRIGGER.GetScene() == MAINMENU)
        {
            MainScene(MAINTRIGGER, LifeHeight, maincount, Sells, lifecount);
        }
        if (MAINTRIGGER.GetScene() == PHLOBBY)
        {
            MainLobby(MAINTRIGGER);
        }
        if (MAINTRIGGER.GetScene() == SETTINGS)
        {
            SettingsScene(MAINTRIGGER);
        }
        if (MAINTRIGGER.GetScene() == WORKSHOP)
        {
            WorkShopScene(MAINTRIGGER);
        }
        if (MAINTRIGGER.GetScene() == CREDITS)
        {
            CreditsScene(MAINTRIGGER);
        }
        
        
    }
    
    UnloadTexture(Sells);

    
    CloseWindow();        
    
    return 0;
}
