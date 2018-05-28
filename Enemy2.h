#pragma once
#include <cocos2d.h>
#include "Enemy1.h"

class Enemy2 : public EnemyGeneral
{
    float Timer;
public:
    Enemy2(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos);
    void ChangeGoal(const cocos2d::Vec2 pos);
    bool Kill() override;
};