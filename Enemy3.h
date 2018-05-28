#pragma once
#include <cocos2d.h>
#include "Enemy1.h"

class Enemy3 : public EnemyGeneral
{
public:
    Enemy3(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos);
    void ChangeGoal(const cocos2d::Vec2 pos);
};