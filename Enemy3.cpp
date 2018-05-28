#include "Enemy3.h"

Enemy3::Enemy3(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos)
    : EnemyGeneral(filenamePicture, lab, pos)
{
    Sprite()->setColor(cocos2d::Color3B::GREEN);
    GetGoal().y += 50;
    GetBase() = cocos2d::Vec2(955, 715);
    Sprite()->setPosition(GetBase());
}

void Enemy3::ChangeGoal(const cocos2d::Vec2 pos)
{
    GetBase() = Sprite()->getPosition();
    GetGoal() = pos;
    GetGoal().y += 50;
}