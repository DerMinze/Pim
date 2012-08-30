#pragma once

#include "Stdafx.h"

namespace Pim
{
	class Vec2
	{
	public:
		Vec2(float px, float py);
		Vec2(void);

		float x, y;
	
		// Operator overloading
		bool operator==(const Vec2 &other);
		bool operator!=(const Vec2 &other);

		Vec2 operator+(const Vec2 &other);
		Vec2 operator-(const Vec2 &other);
		Vec2 operator*(const Vec2 &other);
		Vec2 operator/(const Vec2 &other);

		void operator+=(const Vec2 &other);
		void operator-=(const Vec2 &other);
		void operator*=(const Vec2 &other);
		void operator/=(const Vec2 &other);

		Vec2 operator*(const float &fac);
		Vec2 operator/(float den);
		void operator*=(const float &fac);
		void operator/=(float den);
	};

	struct Rect
	{
		Rect(png_uint_32 xx, png_uint_32 yy, png_uint_32 w, png_uint_32 h) 
			: x(xx), y(yy), width(w), height(h){}

		Rect() 
			: x(0), y(0), width(0), height(0){}

		png_int_32 x, y, width, height;
	};

	struct Color
	{
		Color(float rr, float gg, float bb, float aa) : r(rr), g(gg), b(bb), a(aa) {}
		Color() : r(0.f), g(0.f), b(0.f), a(0.f) {}

		float r, g, b, a;
	};
}
