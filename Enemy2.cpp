#include "Enemy2.h"

Enemy2::Enemy2(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos)
    : EnemyGeneral(filenamePicture, lab, pos)
{
    Sprite()->setColor(cocos2d::Color3B::ORANGE);
    GetGoal().x += 50;
    GetBase() = cocos2d::Vec2(20, 715);
    Sprite()->setPosition(GetBase());
    Timer = rand() % 2 + 1;
}

void Enemy2::ChangeGoal(const cocos2d::Vec2 pos)
{
    GetBase() = Sprite()->getPosition();
    GetGoal() = pos;
    GetGoal().x += 50;
}
bool Enemy2::Kill()
{
    if (Timer <= GetTime())
    {
        GetTime() -= Timer;
        Timer = rand() % 2 + 1;
        return true;
    }
    return false;
}