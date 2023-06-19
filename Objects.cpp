#include "Objects.h"
#include <vector>

Button::Button()
{
    Center.x = Center.y = width = height = mode = 0;
    texture.resize(2);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
}

Button::Button(Vector2 Center, float width, float height)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(2);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
}

Button::Button(Vector2 Center, float width, float height, int mode)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    texture.resize(2);
    this->mode = mode;
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
}

Button::Button(Vector2 Center, float width, float height, std::string title)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
    texture.resize(2);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
}

Button::Button(Vector2 Center, float width, float height, std::string title, int mode)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
    this->mode = mode;
    texture.resize(2);
    this->texture[REGULAR] = LoadTextureFromImage(GenImageColor(width, height, GRAY));
    this->texture[TRIGGERED] = LoadTextureFromImage(GenImageColor(width, height, GREEN));
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

//Button::~Button()
//{
//    for (int i = 0; i <= 1; i++)
//    {
//        UnloadTexture(texture[i]);
//    }
//}

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


void TriggerButton::CheckJob(Vector2 MousePos, Trigger& other)
{
    if (GetHitBox().CheckMouse(MousePos))
    {
        SetChoose(TRIGGERED);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            //other.Job();
        }

        
    }
    else
    {
        SetChoose(REGULAR);
    }
}
