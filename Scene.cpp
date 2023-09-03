#include "Scene.h"

void MainScene(SceneSwitcherTrigger &trigger/*, std::vector<std::vector<Sell>> &LifeHeight, int count, Texture2D Sells, int &lifecount*/)
{
	//Life logic
	/*if (lifecount == 20)
	//{
	//	
	//	for (int i = 0; i < LifeHeight.size(); i++)
	//	{
	//		for (int j = 0; j < LifeHeight[i].size(); j++)
	//		{
	//			//LifeHeight[i][j].Setalive(GetRandomValue(0,1));
	//			int a = CountNeighbours(LifeHeight, i, j);
	//
	//			if (!LifeHeight[i][j].Getalive() && a == 3)
	//				LifeHeight[i][j].Setalive(1);
	//			else if (LifeHeight[i][j].Getalive() && !(a == 2 or a == 3))
	//				LifeHeight[i][j].Setalive(0);
	//		}
	//	}
	//	lifecount = 0;
	//}
	//else
	//{
	//	lifecount++;
	//}*/

	TriggerButton start({ (float)GetScreenWidth() / 2, 12 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Start");
	TriggerButton settings({ (float)GetScreenWidth() / 2, 14 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Settings");
	TriggerButton workshop({ (float)GetScreenWidth() / 2, 16 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "WorkShop");
	TriggerButton credits({ (float)GetScreenWidth() / 2, 18 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Credits");

	start.CheckJob(GetMousePosition(), trigger, PHLOBBY);
	settings.CheckJob(GetMousePosition(), trigger, SETTINGS);
	workshop.CheckJob(GetMousePosition(), trigger, WORKSHOP);
	credits.CheckJob(GetMousePosition(), trigger, CREDITS);

	BeginDrawing();
	ClearBackground(WHITE);
	
	//Draw Life
	/*float s = GetRandomValue(-1, 1);
    for (int i = 0; i < LifeHeight.size(); i++)
    {
        for (int j = 0; j < LifeHeight[i].size(); j++)
        {
			if (LifeHeight[i][j].Getalive())
				DrawTextureV(Sells, { LifeHeight[i][j].GetCenter().x - 15, LifeHeight[i][j].GetCenter().y - 15 }, GRAY);
			else
				DrawTextureV(Sells, { LifeHeight[i][j].GetCenter().x - 15, LifeHeight[i][j].GetCenter().y - 15 }, WHITE);
        }
    }*/

	start.DrawButton();
	settings.DrawButton();
	workshop.DrawButton();
	credits.DrawButton();

	DrawFPS(10, 30);
	EndDrawing();
    
}
void SettingsScene(SceneSwitcherTrigger &trigger)
{
	TriggerButton mainmenu({ (float)GetScreenWidth() / 2, 18 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Back");

	mainmenu.CheckJob(GetMousePosition(), trigger, MAINMENU);
	
	BeginDrawing();
	ClearBackground(WHITE);

	mainmenu.DrawButton();

	DrawFPS(10, 30);
	EndDrawing();
}
void WorkShopScene(SceneSwitcherTrigger& trigger)
{
	TriggerButton mainmenu({ (float)GetScreenWidth() / 2, 18 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Back");

	mainmenu.CheckJob(GetMousePosition(), trigger, MAINMENU);

	BeginDrawing();
	ClearBackground(WHITE);

	mainmenu.DrawButton();

	DrawText("COMING SOON...", GetScreenWidth() / 2 - MeasureText("COMING SOON...", 40) / 2, GetScreenHeight() / 2, 40, GRAY);

	DrawFPS(10, 30);
	EndDrawing();
}
void CreditsScene(SceneSwitcherTrigger& trigger)
{
	TriggerButton mainmenu({ (float)GetScreenWidth() / 2, 18 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Back");

	mainmenu.CheckJob(GetMousePosition(), trigger, MAINMENU);

	BeginDrawing();
	ClearBackground(WHITE);

	mainmenu.DrawButton();

	DrawFPS(10, 30);
	EndDrawing();
}


void MainLobby(SceneSwitcherTrigger& trigger/*, SwitcherTrigger& swTrigger*/)
{
	TriggerButton mainmenu({ (float)GetScreenWidth() - 100, 40 }, GetScreenHeight() / 30, "Back");

	//SwitchButton test({ (float)GetScreenWidth() / 2, 15 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Test");

	mainmenu.CheckJob(GetMousePosition(), trigger, MAINMENU);
	//test.CheckJob(GetMousePosition());

	BeginDrawing();
	ClearBackground(WHITE);

	mainmenu.DrawButton();
	//test.DrawButton();

	DrawFPS(10, 30);
	EndDrawing();
}

