#pragma once
#include <cocos2d.h>
#include <vector>
#include <memory>
#include <set>
#include "GameObject.h"
#include "Shoot.h"

class Player
    : public GameObject
{
public:
     Player(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab);
    ~Player() = default;

    void Update(float delta);
    void AddUserAction(cocos2d::EventKeyboard::KeyCode);
    void RemoveUserAction(cocos2d::EventKeyboard::KeyCode);
    void Update(float x, float y);
    bool HasUserAction(cocos2d::EventKeyboard::KeyCode);
    cocos2d::EventKeyboard::KeyCode Keyboard();
private:
    float X;
    float Y;

    float Speed;
    std::set <cocos2d::EventKeyboard::KeyCode> PressedKeys;
    cocos2d::EventKeyboard::KeyCode Main;
};