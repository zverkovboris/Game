#include "Shoot.h"

Shooting::Shooting(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos, cocos2d::EventKeyboard::KeyCode key)
    : GameObject(filenamePicture, lab)
    , Key(key)
{
    X = pos.x;
    Y = pos.y;
    Sprite()->setPosition(cocos2d::Vec2(X, Y));
    Sprite()->setScale(20 / Sprite()->getContentSize().width);
    if (Key == cocos2d::EventKeyboard::KeyCode::KEY_W)
    {
        Direction = cocos2d::Vec2(0, 5);
    }
    else if (Key == cocos2d::EventKeyboard::KeyCode::KEY_S)
    {
        Direction = cocos2d::Vec2(0, -5);
    }
    else if (Key == cocos2d::EventKeyboard::KeyCode::KEY_A)
    {
        Direction = cocos2d::Vec2(-5, 0);
    }
    else if (Key == cocos2d::EventKeyboard::KeyCode::KEY_D)
    {
        Direction = cocos2d::Vec2(5, 0);
    }
    else
    {
        int x = rand() % 3 - 1;
        if (x == -1)
        {
            Direction = cocos2d::Vec2(-5, 0);
        }
        else if (x == 1)
        {
            Direction = cocos2d::Vec2(5, 0);
        }
        else
        {
            x = rand() % 2;
            if (x == 1)
                Direction = cocos2d::Vec2(0, 5);
            else
                Direction = cocos2d::Vec2(0, -5);
        }
    }
}
bool Shooting::Update()
{
    if (Direction.x > 0)
        if (!CheckRight(this))
            return true;
    if (Direction.x < 0)
        if (!CheckLeft(this))
            return true;
    if (Direction.y > 0)
        if (!CheckUp(this))
            return true;
    if (Direction.y < 0)
        if (!CheckDown(this))
            return true;
    X += Direction.x;
    Y += Direction.y;
    Sprite()->setPosition(cocos2d::Vec2(X, Y));
    return false;
}

void Shooting::Update(float delta)
{

}