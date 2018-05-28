#pragma once
#include <cocos2d.h>
#include "GameObject.h"

class Shooting : public GameObject
{
public:
    Shooting() = default;
    Shooting(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos, cocos2d::EventKeyboard::KeyCode key = cocos2d::EventKeyboard::KeyCode::KEY_0);
    ~Shooting() = default;
    bool Update();
    void Update(float);

private:
    float X;
    float Y;
    cocos2d::Vec2 Direction;
    cocos2d::EventKeyboard::KeyCode Key;
};