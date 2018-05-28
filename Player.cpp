#include "Player.h"
#include <string>

Player::Player(const std::string & filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab)
    : GameObject(filenamePicture, lab)
    , Speed(200)
    , X(400)
    , Y(400)
{
    cocos2d::Vec2 size = Sprite()->getContentSize();
    Sprite()->setScale(45 / size.x);
    Sprite()->setPosition(cocos2d::Vec2(X, Y));
}

cocos2d::EventKeyboard::KeyCode Player::Keyboard()
{
    return Main;
}

void Player::AddUserAction(cocos2d::EventKeyboard::KeyCode key)
{
        PressedKeys.insert(key);
}
void Player::RemoveUserAction(cocos2d::EventKeyboard::KeyCode key)
{
    if (PressedKeys.find(key) != PressedKeys.end())
        PressedKeys.erase(key);
}
bool Player::HasUserAction(cocos2d::EventKeyboard::KeyCode key)
{
    return PressedKeys.find(key) != PressedKeys.end();
}
void Player::Update(float x, float y)
{
    X += x;
    Y += y;
    Sprite()->setPosition(cocos2d::Vec2(X, Y));

    /*if (HasUserAction(cocos2d::EventKeyboard::KeyCode::KEY_SPACE))
    {
        cocos2d::Sprite * Shot = cocos2d::Sprite::create("packman.png");
        Shot->setAnchorPoint(cocos2d::Vec2(0, 0));
        Shot->setPosition(Sprite()->getPosition());
        Shot->setScale(5 / Shot->getContentSize().width);
        Shots.push_back(Shot);
    }*/
}

/*
bool Player::CheckUp(const std::vector<cocos2d::DrawNode *>& labirint)
{
    cocos2d::Size size = View->getContentSize();
    float scale = View->getScale();
    for (size_t i = 0; i < labirint.size(); ++i)
    {
        cocos2d::Size rect = labirint[i]->getContentSize();
        cocos2d::Vec2 pos = labirint[i]->getPosition();
        if (round(Y + size.height * scale) == pos.y)
        {
            if (round(X) > pos.x)
            {
                if (round(X + size.width * scale) < pos.x + rect.width)
                {
                    return false;
                }
                else if (round(X) < pos.x + rect.width)
                {
                    return false;
                }
            }
            else if (round(X + size.width * scale) > pos.x)
            {
                return false;
            }
        }
    }
    return true;
}
bool Player::CheckDown(const std::vector<cocos2d::DrawNode *>& labirint)
{
    cocos2d::Size size = View->getContentSize();
    float scale = View->getScale();
    for (size_t i = 0; i < labirint.size(); ++i)
    {
        cocos2d::Size rect = labirint[i]->getContentSize();
        cocos2d::Vec2 pos = labirint[i]->getPosition();
        if (round(Y) == pos.y + rect.height)
        {
            if (round(X) > pos.x)
            {
                if (round(X + size.width * scale) < pos.x + rect.width)
                {
                    return false;
                }
                else if (round(X) < pos.x + rect.width)
                {
                    return false;
                }
            }
            else if (round(X + size.width * scale) > pos.x)
            {
                return false;
            }
        }
    }
    return true;
}

bool Player::CheckLeft(const std::vector<cocos2d::DrawNode *>& labirint)
{
    cocos2d::Size size = View->getContentSize();
    float scale = View->getScale();
    for (size_t i = 0; i < labirint.size(); ++i)
    {
        cocos2d::Size rect = labirint[i]->getContentSize();
        cocos2d::Vec2 pos = labirint[i]->getPosition();
        if (round(X) == pos.x + rect.width)
        {
            if (round(Y) > pos.y)
            {
                if (round(Y + size.height * scale) < pos.y + rect.height)
                {
                    return false;
                }
                else if (round(Y) < pos.y + rect.height)
                {
                    return false;
                }
            }
            else if (round(Y + size.height * scale) > pos.y)
            {
                return false;
            }
        }
    }
    return true;
}
bool Player::CheckRight(const std::vector<cocos2d::DrawNode *>& labirint)
{
    cocos2d::Size size = View->getContentSize();
    float scale = View->getScale();
    for (size_t i = 0; i < labirint.size(); ++i)
    {
        cocos2d::Size rect = labirint[i]->getContentSize();
        cocos2d::Vec2 pos = labirint[i]->getPosition();
        if (round(X + size.width * scale) == pos.x)
        {
            if (round(Y) > pos.y)
            {
                if (round(Y + size.height * scale) < pos.y + rect.height)
                {
                    return false;
                }
                else if (round(Y) < pos.y + rect.height)
                {
                    return false;
                }
            }
            else if (round(Y + size.height * scale) > pos.y)
            {
                return false;
            }
        }
    }
    return true;
}

*/
void Player::Update(float delta)
{
/*    for (size_t i = 0; i < Shots.size(); ++i)
    {
        cocos2d::Vec2 pos = Shots[i]->getPosition();
        pos.x += 2 * xSpeed * delta;
        pos.y += 2 * ySpeed * delta;
        Shots[i]->setPosition(pos);
    }*/
    if (HasUserAction(cocos2d::EventKeyboard::KeyCode::KEY_W))
    {
            Main = cocos2d::EventKeyboard::KeyCode::KEY_W;
            Update(0, Speed*delta);
            if (!CheckUp(this))
                Update(0, -Speed*delta);
    }
    if (HasUserAction(cocos2d::EventKeyboard::KeyCode::KEY_S))
    {
            Main = cocos2d::EventKeyboard::KeyCode::KEY_S;
            Update(0, -Speed*delta);
            if (!CheckDown(this))
                Update(0, Speed*delta);
    }
    if (HasUserAction(cocos2d::EventKeyboard::KeyCode::KEY_D))
    {
            Main = cocos2d::EventKeyboard::KeyCode::KEY_D;
            Update(Speed*delta, 0);
            if (!CheckRight(this))
                Update(-Speed * delta, 0);
    }
    if (HasUserAction(cocos2d::EventKeyboard::KeyCode::KEY_A))
    {
            Main = cocos2d::EventKeyboard::KeyCode::KEY_A;
            Update(-Speed * delta, 0);
            if (!CheckLeft(this))
                Update(Speed * delta, 0);
    }
}
