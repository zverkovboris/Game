#pragma once
#include <cocos2d.h>
#include "GameObject.h"

class Movable : public GameObject
{
public:

    Movable(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab);
    void Update(float x, float y);
    cocos2d::Vec2 Pos();

private:

    float X;
    float Y;

    float Speed;


};