#include "Labirint.h"

Labirint::Labirint(float x1, float y1, float x2, float y2)
{
    Rect = cocos2d::DrawNode::create();
    Rect->setAnchorPoint(cocos2d::Vec2(0, 0));
    Rect->setPosition(cocos2d::Vec2(x1, y1));
    Rect->setContentSize(cocos2d::Size(x2 - x1, y2 - y1));
    Rect->drawSolidRect(cocos2d::Vec2(0, 0), cocos2d::Vec2(x2 - x1, y2 - y1), cocos2d::Color4F::GREEN);
}

cocos2d::DrawNode * Labirint::Node()
{
    return Rect;
}