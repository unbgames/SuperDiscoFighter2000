#ifndef RECT_HPP
#define RECT_HPP

#include "Vec2.hpp"

class Rect 
{
    public:
        float x, y, w, h;

        Rect();
        Rect(float x, float y, float w, float h);
        Rect(const Rect& r);

        Vec2& Center();
        bool Contains(Vec2 v);
        bool Intersects(Rect r);
        bool Intersects(Rect r, Rect i);
};

#endif
