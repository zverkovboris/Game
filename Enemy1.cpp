#include "Enemy1.h"

EnemyGeneral::EnemyGeneral(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos, cocos2d::Vec2 base)
    : GameObject(filenamePicture, lab)
    , Goal(pos)
    , Speed(150)
    , Move(cocos2d::Vec2(0, 0))
    , Get(false)
    , Time(0)
    , Base(base)
{
    Timer = rand() % 3 + 1;
    Lifes = rand() % 3 + 1;
    Sprite()->setColor(cocos2d::Color3B::RED);
    cocos2d::Vec2 size = Sprite()->getContentSize();
    Sprite()->setScale(45 / size.x);
    Sprite()->setPosition(Base);
}
bool EnemyGeneral::Update(Dir a, float delta)
{
    if (a == Dir::Down)
    {
        if (CheckDown(this))
        {
            Update(cocos2d::Vec2(0, -Speed*delta));
            if (!CheckDown(this))
                Update(cocos2d::Vec2(0, Speed*delta));
            else
                return true;
        }
        return false;
    }
    if (a == Dir::Left)
    {
        if (CheckLeft(this) && Move.x <= 0)
        {
            Update(cocos2d::Vec2(-Speed*delta, 0));
            if (!CheckLeft(this))
                Update(cocos2d::Vec2(Speed*delta, 0));
            else
                return true;
        }
        return false;
    }
    if (a == Dir::Up)
    {
        if (CheckUp(this))
        {
            Update(cocos2d::Vec2(0, Speed*delta));
            if (!CheckUp(this))
                Update(cocos2d::Vec2(0, -Speed*delta));
            else
                return true;
        }
        return false;
    }
    if (a == Dir::Right)
    {
        if (CheckRight(this))
        {
            Update(cocos2d::Vec2(Speed*delta, 0));
            if (!CheckRight(this))
                Update(cocos2d::Vec2(-Speed*delta, 0));
            else
                return true;
        }
        return false;
    }
}
bool EnemyGeneral::Update(Dir fir, Dir sec, bool XorY, float delta)
{
    float g = Goal.x;
    float b = Base.x;
    float m = Move.x;
    if (XorY)
    {
        g = Goal.y;
        b = Base.y;
        m = Move.y;
    }
    if (Move.x != Move.y)
    {
        if (m > 0 || g >= b)
        {
            if (m >= 0)
                if (Update(fir, delta))
                    return true;
        }
        if (m < 0 || b >= g)
        {
            if (m <= 0)
                if (Update(sec, delta))
                    return true;
        }
        if (m == 0)
        {
            if (Update(fir, delta))
                return true;
            if (Update(sec, delta))
                return true;
        }
    }
    return false;
}
void EnemyGeneral::Update(float delta)
{
    Time += delta;
    cocos2d::Vec2 pos = Sprite()->getPosition();
    if (pos.y - Goal.y > Speed*delta && Move.y <= 0)
    {
        if (Update(Dir::Down, delta))
            return;
        if (Update(Dir::Right, Dir::Left, false, delta))
            return;
    }
    else if (pos.y - Goal.y < -1 * Speed*delta && Move.y >= 0)
    {
        if (Update(Dir::Up, delta))
            return;
        if (Update(Dir::Right, Dir::Left, false, delta))
            return;
    }
    if (pos.x - Goal.x > Speed * delta && Move.x <= 0)
    {
        if (Update(Dir::Left, delta))
            return;
        if (Update(Dir::Up, Dir::Down, true, delta))
            return;
    }
    else if (pos.x - Goal.x < -Speed*delta && Move.x >= 0)
    {
        if (Update(Dir::Right, delta))
            return;
        if (Update(Dir::Up, Dir::Down, true, delta))
            return;
    }
    if (std::abs(Goal.y - pos.y) < Speed * delta)
    {
        if (pos.y != Goal.y)
        {
            Sprite()->setPositionY(Goal.y);
            return;
        }
    }
    if (std::abs(Goal.x - pos.x) < Speed * delta)
    {
        if (pos.x != Goal.x)
        {
            Sprite()->setPositionX(Goal.x);
            return;
        }
    }
    Get = true;
}
void EnemyGeneral::Update(cocos2d::Vec2 next)
{
    cocos2d::Vec2 pos = Sprite()->getPosition();
    pos.x += next.x;
    pos.y += next.y;
    Sprite()->setPosition(pos);
}

void EnemyGeneral::ChangeGoal(const cocos2d::Vec2 pos)
{
    Get = false;
    Base = Sprite()->getPosition();
    Goal = pos;
}

cocos2d::Vec2& EnemyGeneral::GetGoal()
{
    return Goal;
}
float& EnemyGeneral::GetTime()
{
    return Time;
}

cocos2d::Vec2& EnemyGeneral::GetBase()
{
    return Base;
}

void EnemyGeneral::ChangeMove(cocos2d::Vec2 Lastpos)
{
    cocos2d::Vec2 pos = Sprite()->getPosition();
    if (std::abs(pos.x - Lastpos.x) > 2)
    {
        if (Move.y != 0)
        {
            Base = pos;
        }
        Move.x = pos.x - Lastpos.x;
        Move.y = 0;
    }
    else if (std::abs(pos.y - Lastpos.y) > 2)
    {
        if (Move.x != 0)
        {
            Base = pos;
        }
        Move.y = pos.y - Lastpos.y;
        Move.x = 0;
    }
}

bool EnemyGeneral::Reached()
{
    if (Get)
        Move = cocos2d::Vec2(0, 0);
    return Get;
}

int& EnemyGeneral::GetLifes()
{
    return Lifes;
}

bool EnemyGeneral::Kill()
{
    if (Timer <= GetTime())
    {
        GetTime() -= Timer;
        Timer = rand() % 2 + 1;
        return true;
    }
    return false;
}