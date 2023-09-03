#include "Objects.h"
#include <vector>


//void InitMainButtons(std::unordered_map<std::string, std::vector<Button>>& MainB)
//{
//    std::vector<Button> MMM;
//    MainB["MAINMENU"] = MMM;
//    //MAINMENU
//    TriggerButton start({ (float)GetScreenWidth() / 2, 12 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Start");
//    TriggerButton settings({ (float)GetScreenWidth() / 2, 14 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Settings");
//    TriggerButton workshop({ (float)GetScreenWidth() / 2, 16 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "WorkShop");
//    TriggerButton credits({ (float)GetScreenWidth() / 2, 18 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Credits");
//
//    MainB["MAINMENU"].push_back(start);
//    MainB["MAINMENU"].push_back(settings);
//    MainB["MAINMENU"].push_back(workshop);
//    MainB["MAINMENU"].push_back(credits);
//
//    ////SETTINGS
//    //TriggerButton mainmenu({ (float)GetScreenWidth() / 2, 18 * (float)GetScreenHeight() / 30 }, GetScreenHeight() / 30, "Back");
//
//    //MainB[1].push_back(mainmenu);
//
//    ////WORKSHOP
//    //MainB[2].push_back(mainmenu);
//
//    ////CREDITS
//    //MainB[3].push_back(mainmenu);
//}

Button::Button()
{
    Center.x = Center.y = width = height = 0;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

Button::Button(Button& other)
{
    SetCenter(other.GetCenter());
    SetWidth(other.GetWidth());
    SetHeight(other.GetHeight());
    SimpleHitBox a(GetCenter(), GetWidth(), GetHeight());
    SetButtonHitBox(a);
    SetTitle(other.GetTitle());
    GetTexture().resize(2);
    GetTexture()[REGULAR] = LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), GRAY));
    GetTexture()[TRIGGERED] = LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), GREEN));
}

Button::Button(Vector2 Center, float width, float height)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

Button::Button(Vector2 Center, float width, float height, int FontSize)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(3);
    this->FontSize = FontSize;
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

Button::Button(Vector2 Center, float width, float height, std::string title)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

Button::Button(Vector2 Center, float width, float height, std::string title, int FontSize)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
    this->FontSize = FontSize;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

Button::Button(Vector2 Center, float height, std::string title)
{
    this->Center = Center;
    this->height = height;
    this->title = title;
    width = MeasureText(title.c_str(), 30) + 10;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

Button::Button(Vector2 Center, float height, std::string title, int FrontSize)
{
    this->Center = Center;
    this->height = height;
    this->title = title;
    width = MeasureText(title.c_str(), FontSize) + 10;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

//Button::Button(Vector2 Center, float width, float height, Image texture)
//{
//    this->Center = Center;
//    this->width = width;
//    this->height = height;
//    SimpleHitBox a(Center, width, height);
//    HitBox = a;
//    this->texture = texture;
//}
//
//Button::Button(Vector2 Center, float width, float height, Image texture, int mode)
//{
//    this->Center = Center;
//    this->width = width;
//    this->height = height;
//    SimpleHitBox a(Center, width, height);
//    HitBox = a;
//    this->texture = texture;
//    this->mode = mode;
//}
//
//Button::Button(Vector2 Center, float width, float height, std::string title, Image texture)
//{
//    this->Center = Center;
//    this->width = width;
//    this->height = height;
//    SimpleHitBox a(Center, width, height);
//    HitBox = a;
//    this->title = title;
//    this->texture = texture;
//}
//
//Button::Button(Vector2 Center, float width, float height, std::string title, Image texture, int mode)
//{
//    this->Center = Center;
//    this->width = width;
//    this->height = height;
//    SimpleHitBox a(Center, width, height);
//    HitBox = a;
//    this->title = title;
//    this->texture = texture;
//    this->mode = mode;
//}

Button::~Button()
{
    for (int i = 0; i <= 2; i++)
    {
        UnloadTexture(texture[i]);
    }
}



void Button::SetAll(Vector2 Center, float height, std::string title)
{
    this->Center = Center;
    this->height = height;
    this->title = title;
    width = MeasureText(title.c_str(), 30) + 10;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(3);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
    this->texture[ACTIVE] = LoadTextureFromImage(GenImageColor(width, height, DARKGREEN));
}

void Button::SetButtonHitBox(SimpleHitBox HitBox)
{
    this->HitBox = HitBox;
}

void Button::SetCenter(Vector2 Center)
{
    this->Center = Center;
}

void Button::SetTitle(std::string title)
{
    this->title = title;
}

void Button::SetWidth(float width)
{
    this->width = width;
}

void Button::SetHeight(float height)
{
    this->height = height;
}

void Button::SetWidthAndHeight(float width, float height)
{
    this->width = width;
    this->height = height;
}

void Button::SetChoose(bool choose)
{
    this->choose = choose;
}

SimpleHitBox Button::GetHitBox()
{
    return HitBox;
}

Vector2 Button::GetCenter()
{
    return Center;
}

std::vector<Texture2D> Button::GetTexture()
{
    return texture;
}

std::string Button::GetTitle()
{
    return title;
}

float Button::GetWidth()
{
    return width;
}

float Button::GetHeight()
{
    return height;
}

bool Button::GetChoose()
{
    return choose;
}

void Button::DrawButton()
{
    DrawTextureV(texture[choose], { HitBox.GetMinXMinY().GetPosition().x , HitBox.GetMinXMinY().GetPosition().y + height/2 }, WHITE);
    DrawText(title.c_str(), Center.x - MeasureText(title.c_str(), FontSize) / 2, Center.y + FontSize /2, FontSize, LIGHTGRAY);
}

void Button::DrawButton(int FontSize)
{
    this->FontSize = FontSize;
    DrawTextureV(texture[choose], HitBox.GetMinXMinY().GetPosition(), WHITE);
    DrawText(title.c_str(), Center.x - MeasureText(title.c_str(), FontSize) / 2, Center.y + FontSize / 2, FontSize, LIGHTGRAY);
}


TriggerButton::TriggerButton(Button &other)
{
    SetCenter(other.GetCenter());
    SetWidth(other.GetWidth());
    SetHeight(other.GetHeight());
    SimpleHitBox a(GetCenter(), GetWidth(), GetHeight());
    SetButtonHitBox(a);
    SetTitle(other.GetTitle());
    GetTexture().resize(2);
    GetTexture()[REGULAR] = LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), GRAY));
    GetTexture()[TRIGGERED] = LoadTextureFromImage(GenImageColor(GetWidth(), GetHeight(), GREEN));
}

void TriggerButton::CheckJob(Vector2 MousePos, Trigger& other, double Scene)
{
    if (GetHitBox().CheckMouse(MousePos))
    {
        SetChoose(TRIGGERED);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            other.Job(Scene);
        }
    }
    else
    {
        SetChoose(REGULAR);
    }
}

//void SwitchButton::CheckJob(Vector2 MousePos)
//{
//    if (GetHitBox().CheckMouse(MousePos))
//    {
//        if (!IsActive)
//        {
//            SetChoose(TRIGGERED);
//        }
//        else
//        {
//            SetChoose(ACTIVE);
//        }
//        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
//        {
//            IsActive = !IsActive;
//        }
//    }
//    else
//    {
//        SetChoose(REGULAR);
//    }
//}
