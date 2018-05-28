#pragma once
#include<cocos2d.h>
#include "GameObject.h"
#include "Player.h"

class EnemyGeneral
    : public GameObject
{
public:
    EnemyGeneral(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos);
    void Update(float delta);
    void Update(cocos2d::Vec2 next);
    void ChangeGoal(const cocos2d::Vec2 pos);
    cocos2d::Vec2& GetGoal();
    cocos2d::Vec2& GetBase();
    void ChangeMove(cocos2d::Vec2 Lastpos);
    bool Reached();
    int& GetLifes();
    float& GetTime();
    virtual bool Kill();

private:
    float Time;
    cocos2d::Vec2 Move;
    cocos2d::Vec2 Base;
    cocos2d::Vec2 Goal;

    bool Get;
    int  Lifes;
    float Speed;
};