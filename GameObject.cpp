#include "GameObject.h"

cocos2d::Sprite* GameObject::Sprite()
{
    return Object;
}

GameObject::GameObject(const std::string& filenamePicture, const std::vector<std::shared_ptr<Labirint>>& lab)
{
    Lab = std::move(lab);
    Object = cocos2d::Sprite::create(filenamePicture);
    Object->setAnchorPoint(cocos2d::Vec2(0, 0));
    Object->setScale(45 / Object->getContentSize().width);
}

bool GameObject::CheckLeft(GameObject * obj)
{
    cocos2d::Size rectFirst = obj->Object->getContentSize();
    float scale = obj->Object->getScale();
    cocos2d::Vec2 posFirst = obj->Object->getPosition();
    for (size_t i = 0; i < obj->Lab.size(); ++i)
    {
        cocos2d::Size rectSecond = obj->Lab[i]->Node()->getContentSize();
        cocos2d::Vec2 posSecond = obj->Lab[i]->Node()->getPosition();
        if ((posFirst.x < posSecond.x + rectSecond.width) && (posFirst.x + rectFirst.width * scale > posSecond.x + rectSecond.width))
        {
            if (posFirst.y > posSecond.y)
            {
                if (posFirst.y + rectFirst.height * scale < posSecond.y + rectSecond.height)
                {
                    return false;
                }
                else if (posFirst.y < posSecond.y + rectSecond.height)
                {
                    return false;
                }
            }
            else if (posFirst.y + rectFirst.height * scale > posSecond.y)
            {
                return false;
            }
        }
    }
    return true;
}

bool GameObject::CheckRight(GameObject * obj)
{
    cocos2d::Size rectFirst = obj->Object->getContentSize();
    float scale = obj->Object->getScale();
    cocos2d::Vec2 posFirst = obj->Object->getPosition();
    for (size_t i = 0; i < obj->Lab.size(); ++i)
    {
        cocos2d::Size rectSecond = obj->Lab[i]->Node()->getContentSize();
        cocos2d::Vec2 posSecond = obj->Lab[i]->Node()->getPosition();
        if ((posFirst.x + rectFirst.width * scale > posSecond.x) && (posFirst.x < posSecond.x))
        {
            if (posFirst.y > posSecond.y)
            {
                if (posFirst.y + rectFirst.height * scale < posSecond.y + rectSecond.height)
                {
                    return false;
                }
                else if (posFirst.y < posSecond.y + rectSecond.height)
                {
                    return false;
                }
            }
            else if (posFirst.y + rectFirst.height * scale > posSecond.y)
            {
                return false;
            }
        }
    }
    return true;
}

bool GameObject::CheckDown(GameObject * obj)
{
    cocos2d::Size rectFirst = obj->Object->getContentSize();
    float scale = obj->Object->getScale();
    cocos2d::Vec2 posFirst = obj->Object->getPosition();
    for (size_t i = 0; i < obj->Lab.size(); ++i)
    {
        cocos2d::Size rectSecond = obj->Lab[i]->Node()->getContentSize();
        cocos2d::Vec2 posSecond = obj->Lab[i]->Node()->getPosition();
        if ((posFirst.y < posSecond.y + rectSecond.height) && (posFirst.y + rectFirst.height * scale > posSecond.y + rectSecond.height))
        {
            if (posFirst.x > posSecond.x)
            {
                if (posFirst.x + rectFirst.width * scale < posSecond.x + rectSecond.width)
                {
                    return false;
                }
                else if (posFirst.x < posSecond.x + rectSecond.width)
                {
                    return false;
                }
            }
            else if (posFirst.x + rectFirst.width * scale > posSecond.x)
            {
                return false;
            }
        }
    }
    return true;
}

bool GameObject::CheckUp(GameObject * obj)
{
    cocos2d::Size rectFirst = obj->Object->getContentSize();
    float scale = obj->Object->getScale();
    cocos2d::Vec2 posFirst = obj->Object->getPosition();
    for (size_t i = 0; i < obj->Lab.size(); ++i)
    {
        cocos2d::Size rectSecond = obj->Lab[i]->Node()->getContentSize();
        cocos2d::Vec2 posSecond = obj->Lab[i]->Node()->getPosition();
        if ((posFirst.y + rectFirst.height * scale > posSecond.y) && (posFirst.y < posSecond.y))
        {
            if (posFirst.x > posSecond.x)
            {
                if (posFirst.x + rectFirst.width * scale < posSecond.x + rectSecond.width)
                {
                    return false;
                }
                else if (posFirst.x < posSecond.x + rectSecond.width)
                {
                    return false;
                }
            }
            else if (posFirst.x + rectFirst.width * scale > posSecond.x)
            {
                return false;
            }
        }
    }
    return true;
}

bool GameObject::Collision(cocos2d::Node * first, cocos2d::Node * second)
{
    if (first == second)
        return false;
    float s1 = first->getScale();
    float s2 = second->getScale();
    float x1 = first->getPosition().x;
    float y1 = first->getPosition().y;
    float x2 = second->getPosition().x;
    float y2 = second->getPosition().y;
    float h1 = first->getContentSize().height;
    float w1 = first->getContentSize().width;
    float h2 = second->getContentSize().height;
    float w2 = second->getContentSize().width;
    return ((x2 - x1 < w1 * s1) && (x1 - x2 < w2 * s2)
        && (y2 - y1 < h1 * s1) && (y1 - y2 < h2 * s2));
}

bool GameObject::Collision(GameObject * obj)
{
    float s1 = obj->Object->getScale();
    float x1 = obj->Object->getPosition().x;
    float y1 = obj->Object->getPosition().y;
    float h1 = obj->Object->getContentSize().height;
    float w1 = obj->Object->getContentSize().width;
    for (size_t i = 0; i < obj->Lab.size(); ++i)
    {
        float x2 = obj->Lab[i]->Node()->getPosition().x;
        float y2 = obj->Lab[i]->Node()->getPosition().y;
        float h2 = obj->Lab[i]->Node()->getContentSize().height;
        float w2 = obj->Lab[i]->Node()->getContentSize().width;
        if (((std::abs(x2 - x1) < w2) || (std::abs(x2 - x1) < w1 * s1))
            && ((std::abs(y2 - y1) < h2) || (std::abs(y2 - y1) < h1 * s1)))
        {
            return true;
        }
    }
    return false;
}
