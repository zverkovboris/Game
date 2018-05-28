#pragma once
#include <cocos2d.h>

class Labirint
{
public:
    Labirint(float x1, float y1, float x2, float y2);
    virtual ~Labirint() = default;

    cocos2d::DrawNode * Node();

private:

    cocos2d::DrawNode * Rect;
};