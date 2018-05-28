#include "Movable.h"

Movable::Movable(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab)
    : GameObject(filenamePicture, lab)
    , Speed(150)
    , X(20)
    , Y(10)
{

}

void Movable::Update(float x, float y)
{
    X += x;
    Y += y;
    Sprite()->setPosition(cocos2d::Vec2(X, Y));
}

cocos2d::Vec2 Movable::Pos()
{
    return cocos2d::Vec2(X, Y);
}