#pragma once
#include <cocos2d.h>
#include "Labirint.h"
#include <memory>
#include <math.h>

class GameObject
{
public:
    GameObject(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab);
    virtual ~GameObject() = default;

    virtual void Update(float) = 0;

    cocos2d::Sprite * Sprite();

    static bool Collision(GameObject * obj);
    static bool Collision(cocos2d::Node * first, cocos2d::Node * second);
    static bool CheckLeft(GameObject * obj);
    static bool CheckUp(GameObject * obj);
    static bool CheckRight(GameObject * obj);
    static bool CheckDown(GameObject * obj);

private:

    std::vector<std::shared_ptr<Labirint>> Lab;

    cocos2d::Sprite * Object;
};