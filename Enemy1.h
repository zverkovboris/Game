#pragma once
#include<cocos2d.h>
#include "GameObject.h"
#include "Player.h"

class EnemyGeneral
    : public GameObject
{
public:
    enum Dir
    {
        Up,
        Left,
        Down,
        Right
    };
    EnemyGeneral(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos, cocos2d::Vec2 base);
    void Update(float delta);
    void Update(cocos2d::Vec2 next);
    void ChangeGoal(const cocos2d::Vec2 pos);
    bool Update(Dir a, Dir b, bool XorY, float delta);
    cocos2d::Vec2& GetGoal();
    cocos2d::Vec2& GetBase();
    void ChangeMove(cocos2d::Vec2 Lastpos);
    bool Reached();
    int& GetLifes();
    float& GetTime();
    bool Kill();
    bool Update(Dir, float);

private:
    
    float Time;
    float Timer;
    cocos2d::Vec2 Move;
    cocos2d::Vec2 Base;
    cocos2d::Vec2 Goal;

    bool Get;
    int  Lifes;
    float Speed;
};