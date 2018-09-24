#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>

class Vec2 
{
    public:
        float x, y;
        
        Vec2();
        Vec2(float x, float y);
        Vec2(const Vec2& v);

        Vec2 operator+(float s);
        Vec2 operator-(float s);
		Vec2 operator*(float s);
	    Vec2 operator/(float s);
	    Vec2& operator+=(float s);
    	Vec2& operator-=(float s);
	    Vec2& operator*=(float s);
		Vec2& operator/=(float s);
		Vec2 operator+(Vec2& v);
		Vec2 operator-(Vec2& v);
		Vec2& operator+=(Vec2& v);
		Vec2& operator-=(Vec2& v);
	    
	    void Rotate(float deg);
		Vec2& Normalize();
		float Distance(Vec2 v) const;
        float Length() const;
        void Truncate(float length);
		Vec2 Ortho() const;
	    static float Dot(Vec2 v1, Vec2 v2);
	    static float Cross(Vec2 v1, Vec2 v2);
};

#endif