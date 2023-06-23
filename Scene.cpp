#include "Scene.h"

void MainScene(SceneSwitcherTrigger trigger, std::vector<std::vector<Sell>> &LifeHeight, int count, Texture2D Sells, int &lifecount)
{
	//Life logic
	if (lifecount == 5)
	{
		
		for (int i = 0; i < LifeHeight.size(); i++)
		{
			for (int j = 0; j < LifeHeight[i].size(); j++)
			{
				//LifeHeight[i][j].Setalive(GetRandomValue(0,1));
				int a = CountNeighbours(LifeHeight, i, j);

				if (!LifeHeight[i][j].Getalive() && a == 3)
					LifeHeight[i][j].Setalive(1);
				else if (LifeHeight[i][j].Getalive() && !(a == 2 or a == 3))
					LifeHeight[i][j].Setalive(0);
			}
		}
		lifecount = 0;
	}
	else
	{
		lifecount++;
	}
	TriggerButton start({ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 }, GetScreenWidth() / 50, GetScreenHeight() / 20, LoadFileText("/Localization/en.txt"));
	start.CheckJob(GetMousePosition(), trigger, 0.1);

	BeginDrawing();
	ClearBackground(WHITE);
	
	//Draw Life
	float s = GetRandomValue(-1, 1);
    for (int i = 0; i < LifeHeight.size(); i++)
    {
        for (int j = 0; j < LifeHeight[i].size(); j++)
        {
			if (LifeHeight[i][j].Getalive())
				DrawTextureV(Sells, { LifeHeight[i][j].GetCenter().x - 15, LifeHeight[i][j].GetCenter().y - 15 }, GRAY);
			else
				DrawTextureV(Sells, { LifeHeight[i][j].GetCenter().x - 15, LifeHeight[i][j].GetCenter().y - 15 }, WHITE);
        }
    }
	start.DrawButton();
	EndDrawing();
    
}
