#include "Objects.h"

Vector2 TransformPos2CPos(Vector2 pos)
{
    pos.y *= -1;
    return pos;
}

Vector2 TransformPos2CPos(Point pos)
{
    Vector2 a = pos.GetPosition();
    a.y *= -1;
    return a;
}

Button::Button()
{
    Center.x = Center.y = width = height = mode = 0;
}

Button::Button(Vector2 Center, float width, float height)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
}

Button::Button(Vector2 Center, float width, float height, int mode)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->mode = mode;
}

Button::Button(Vector2 Center, float width, float height, std::string title)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
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
}

Button::Button(Vector2 Center, float width, float height, Image texture)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->texture = texture;
}

Button::Button(Vector2 Center, float width, float height, Image texture, int mode)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->texture = texture;
    this->mode = mode;
}

Button::Button(Vector2 Center, float width, float height, std::string title, Image texture)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
    this->texture = texture;
}

Button::Button(Vector2 Center, float width, float height, std::string title, Image texture, int mode)
{
    this->Center = Center;
    this->width = width;
    this->height = height;
    SimpleHitBox a(Center, width, height);
    HitBox = a;
    this->title = title;
    this->texture = texture;
    this->mode = mode;
}

void Button::SetButtonHitBox(SimpleHitBox HitBox)
{
    this->HitBox = HitBox;
}

void Button::SetCenter(Vector2 Center)
{
    this->Center = Center;
}

void Button::SetTexture(Image texture)
{
    this->texture = texture;
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

void Button::SetMode(int mode)
{
    this->mode = mode;
}

SimpleHitBox Button::GetHitBox()
{
    return HitBox;
}

Vector2 Button::GetCenter()
{
    return Center;
}

Image Button::GetTexture()
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

int Button::GetMode()
{
    return mode;
}

