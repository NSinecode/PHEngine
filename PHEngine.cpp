#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "HitBox.h"
#include "Objects.h"
#include "Addons.h"
#include "Scene.h"

//Font NewDefault = LoadFont("Fronts/LUCON.TTF");

//Def FontDef;

int main()
{
    
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "PHEngine");
    

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    TriggerButton Anya(TransformPos2CPos({500, -250}), 150, 20, "First Button");
    Trigger a;

    while (!WindowShouldClose())        
    {
        /*
        //----------------------------------------------------------------------------------
        // Translate based on mouse right click
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f / camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }
        
        
        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

            // Set the offset to where the mouse is
            camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

            // Zoom increment
            const float zoomIncrement = 0.125f;

            camera.zoom += (wheel * zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);

        BeginMode2D(camera);

        // Draw the 3d grid, rotated 90 degrees and centered around 0,0 
        // just so we have something in the XY plane
        rlPushMatrix();
        rlTranslatef(0, 25 * 50, 0);
        rlRotatef(90, 1, 0, 0);
        //DrawGrid(200, 1000);
        rlPopMatrix();

        // Draw a reference circle
        DrawCircle(0, 100, 50, YELLOW);

        EndMode2D();

        DrawText("Mouse right button drag to move, mouse wheel to zoom", 10, 10, 20, WHITE);

        EndDrawing();
        */

        Anya.CheckJob(GetMousePosition(), a);
        
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(camera);

        rlPushMatrix();
        rlTranslatef(0, 25 * 50, 0);
        rlRotatef(90, 1, 0, 0);
        //DrawGrid(200, 1000);
        rlPopMatrix();

        
        
        
        Anya.DrawButton();

        EndMode2D();
        EndDrawing();

    }
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    
    return 0;
}
