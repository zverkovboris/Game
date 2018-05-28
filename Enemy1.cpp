#include "Enemy1.h"

EnemyGeneral::EnemyGeneral(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab, cocos2d::Vec2 pos)
    : GameObject(filenamePicture, lab)
    , Goal(pos)
    , Speed(150)
    , Move(cocos2d::Vec2(0, 0))
    , Get(false)
    , Time(0)
{
    Lifes = rand() % 3 + 1;
    Sprite()->setColor(cocos2d::Color3B::RED);
    cocos2d::Vec2 size = Sprite()->getContentSize();
    Sprite()->setScale(45 / size.x);
    Base = cocos2d::Vec2(955, 10);
    Sprite()->setPosition(Base);
}

void EnemyGeneral::Update(float delta)
{
    Time += delta;
    Get = false;
    cocos2d::Vec2 pos = Sprite()->getPosition();
    if (pos.y - Goal.y > Speed*delta && Move.y <= 0)
    {
        if (CheckDown(this))
        {
            Update(cocos2d::Vec2(0, -Speed*delta));
            if (!CheckDown(this))
                Update(cocos2d::Vec2(0, Speed*delta));
            else
            return;
        }
        if (Move.x != Move.y)
        {
            if (Move.x > 0 || Goal.x >= Base.x)
            {
                if (CheckRight(this) && Move.x >= 0)
                {
                    Update(cocos2d::Vec2(Speed*delta, 0));
                    if (!CheckRight(this))
                        Update(cocos2d::Vec2(-Speed*delta, 0));
                    else
                    return;
                }
            }
            if (Move.x < 0 || Base.x >= Goal.x)
            {
                if (CheckLeft(this) && Move.x <= 0)
                {
                    Update(cocos2d::Vec2(-Speed*delta, 0));
                    if (!CheckLeft(this))
                        Update(cocos2d::Vec2(Speed*delta, 0));
                    else
                    return;
                }
            }
            if (Move.x == 0)
            {
                if (CheckRight(this))
                {
                    Update(cocos2d::Vec2(Speed*delta, 0));
                    if (!CheckRight(this))
                        Update(cocos2d::Vec2(-Speed*delta, 0));
                    else
                        return;
                }
                if (CheckLeft(this))
                {
                    Update(cocos2d::Vec2(-Speed*delta, 0));
                    if (!CheckLeft(this))
                        Update(cocos2d::Vec2(Speed*delta, 0));
                    else
                        return;
                }
            }
        }
    }
    else if (pos.y - Goal.y < -1 * Speed*delta && Move.y >= 0)
    {
        if (CheckUp(this))
        {
            Update(cocos2d::Vec2(0, Speed*delta));
            if (!CheckUp(this))
                Update(cocos2d::Vec2(0, -Speed*delta));
            else
            return;
        }
        if (Move.x != Move.y)
        {
            if (Move.x > 0 || Goal.x >= Base.x)
            {
                if (CheckRight(this) && Move.x >= 0)
                {
                    Update(cocos2d::Vec2(Speed*delta, 0));
                    if (!CheckRight(this))
                        Update(cocos2d::Vec2(-Speed*delta, 0));
                    else
                        return;
                }
            }
            if (Move.x < 0 || Base.x >= Goal.x)
            {
                
                if (CheckLeft(this) && Move.x <= 0)
                {
                    Update(cocos2d::Vec2(-Speed*delta, 0));
                    if (!CheckLeft(this))
                        Update(cocos2d::Vec2(Speed*delta, 0));
                    else
                    return;
                }
            }
            if (Move.x == 0)
            {
                if (CheckRight(this))
                {
                    Update(cocos2d::Vec2(Speed*delta, 0));
                    if (!CheckRight(this))
                        Update(cocos2d::Vec2(-Speed*delta, 0));
                    else
                        return;
                }
                if (CheckLeft(this))
                {
                    Update(cocos2d::Vec2(-Speed*delta, 0));
                    if (!CheckLeft(this))
                        Update(cocos2d::Vec2(Speed*delta, 0));
                    else
                        return;
                }
            }
        }
    }
    
    if (pos.x - Goal.x > Speed * delta && Move.x <= 0)
    {
        if (CheckLeft(this))
        {
            Update(cocos2d::Vec2(-Speed * delta, 0));
            if (!CheckLeft(this))
                Update(cocos2d::Vec2(Speed*delta, 0));
            else
                return;
        }
        if (Move.x != Move.y)
        {
            if (Move.y > 0 || Goal.y >= Base.y)
            {
                if (CheckUp(this) && Move.y >= 0)
                {
                    Update(cocos2d::Vec2(0, Speed*delta));
                    if (!CheckUp(this))
                        Update(cocos2d::Vec2(0, -Speed*delta));
                    else
                    return;
                }
            }
            if (Move.y < 0 || Base.y >= Goal.y)
            {
                if (CheckDown(this) && Move.y <= 0)
                {
                    Update(cocos2d::Vec2(0, -Speed*delta));
                    if (!CheckDown(this))
                        Update(cocos2d::Vec2(0, Speed*delta));
                    else
                    return;
                }
            }
            if (Move.y == 0)
            {
                if (CheckUp(this))
                {
                    Update(cocos2d::Vec2(0, Speed*delta));
                    if (!CheckUp(this))
                        Update(cocos2d::Vec2(0, -Speed*delta));
                    else
                        return;
                }
                if (CheckDown(this))
                {
                    Update(cocos2d::Vec2(0, -Speed*delta));
                    if (!CheckDown(this))
                        Update(cocos2d::Vec2(0, Speed*delta));
                    else
                        return;
                }
            }
        }
    }
    else if (pos.x - Goal.x < -Speed*delta && Move.x >= 0)
    {
         if (CheckRight(this))
         {
             Update(cocos2d::Vec2(Speed*delta, 0));
             if (!CheckRight(this))
                 Update(cocos2d::Vec2(-Speed*delta, 0));
             else
             return;
         }
         if (Move.x != Move.y)
         {
             if (Move.y > 0 || Goal.y >= Base.y)
             {
                 if (CheckUp(this) && Move.y >= 0)
                 {
                     Update(cocos2d::Vec2(0, Speed*delta));
                     if (!CheckUp(this))
                         Update(cocos2d::Vec2(0, -Speed*delta));
                     else
                         return;
                 }
             }
             if (Move.y < 0 || Base.y >= Goal.y)
             {
                 if (CheckDown(this) && Move.y <= 0)
                 {
                     Update(cocos2d::Vec2(0, -Speed*delta));
                     if (!CheckDown(this))
                         Update(cocos2d::Vec2(0, Speed*delta));
                     else
                         return;
                 }
             }
             if (Move.y == 0)
             {
                 if (CheckUp(this))
                 {
                     Update(cocos2d::Vec2(0, Speed*delta));
                     if (!CheckUp(this))
                         Update(cocos2d::Vec2(0, -Speed*delta));
                     else
                         return;
                 }
                 if (CheckDown(this))
                 {
                     Update(cocos2d::Vec2(0, -Speed*delta));
                     if (!CheckDown(this))
                         Update(cocos2d::Vec2(0, Speed*delta));
                     else
                         return;
                 }
             }
         }
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
        if (Move.x == 0 || Move.y != 0)
        {
            Base = pos;
        }
        Move.x = pos.x - Lastpos.x;
        Move.y = 0;
    }
    else if (std::abs(pos.y - Lastpos.y) > 2)
    {
        if (Move.y == 0 || Move.x != 0)
        {
            Base = pos;
        }
        Move.y = pos.y - Lastpos.y;
        Move.x = 0;
    }
}

bool EnemyGeneral::Reached()
{
    return Get;
}

int& EnemyGeneral::GetLifes()
{
    return Lifes;
}

bool EnemyGeneral::Kill()
{
    return false;
}
