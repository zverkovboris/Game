#include "Enemy4.h"

Enemy4::Enemy4(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos)
    : EnemyGeneral(filenamePicture, lab, pos)
{
    Sprite()->setColor(cocos2d::Color3B::GRAY);
    GetGoal().x -= 50;
    GetGoal().y -= 50;
    GetBase() = cocos2d::Vec2(20, 10);
    Sprite()->setPosition(GetBase());
    Timer = rand() % 3 + 1;
}

void Enemy4::ChangeGoal(const cocos2d::Vec2 pos)
{
    GetBase() = Sprite()->getPosition();
    GetGoal() = pos;
    GetGoal().y -= 50;
    GetGoal().x -= 50;
}
bool Enemy4::Kill()
{
    if (Timer <= GetTime())
    {
        GetTime() -= Timer;
        Timer = rand() % 3 + 1;
        return true;
    }
    return false;
}