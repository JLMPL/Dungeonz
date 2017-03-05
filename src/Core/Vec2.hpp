#ifndef VEC2_HPP
#define VEC2_HPP
#include <cmath>
#include <SFML/System/Vector2.hpp>

template <typename T>
struct vec2
{
	T x = 0;
	T y = 0;

	vec2() {}

	vec2(const T& x, const T& y)
	{
		this->x = x;
		this->y = y;
	}

	template <typename U>
	vec2(const vec2<U>& vec)
	{
		x = static_cast<T>(vec.x);
		y = static_cast<T>(vec.y);
	}

	template <typename S>
	vec2<T> operator*(S s)
	{
		T scalar = static_cast<T>(s);
		return vec2<T>(x * s, y * s);
	}

	template <typename U>
	vec2<T> operator+(const vec2<U>& v) const
	{
		return vec2<T>(x + static_cast<T>(v.x), y + static_cast<T>(v.y));
	}

	template <typename U>
	vec2<T> operator-(const vec2<U>& v) const
	{
		return vec2<T>(x - static_cast<T>(v.x), y - static_cast<T>(v.y));
	}

	template <typename U>
	vec2<T>& operator+=(const vec2<U>& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		return *this;
	}

	template <typename U>
	bool operator!=(const vec2<U>& v) const
	{
		return x != static_cast<T>(v.x) and y != static_cast<T>(v.y);
	}

	sf::Vector2f getSfVecf() const
	{
		return sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
	}

	sf::Vector2i getSfVeci() const
	{
		return sf::Vector2i(static_cast<int>(x), static_cast<int>(y));
	}

	vec2<float> getf() const
	{
		return vec2<float>(static_cast<float>(x), static_cast<float>(y));
	}

	vec2<int> geti() const
	{
		return vec2<int>(static_cast<int>(x), static_cast<int>(y));
	}
};

template <typename T>
static float dot(vec2<T> a, vec2<T> b)
{
	return a.x * b.x + a.y * b.y;
}

template <typename T>
static float length(const vec2<T>& v)
{
	return sqrt(static_cast<float>(v.x*v.x + v.y*v.y));
}

template <typename T>
static float distance(const vec2<T>& a, const vec2<T>& b)
{
	return length(b - a);
}

template <typename T>
static vec2<T> normalize(const vec2<T>& v)
{
	vec2<T> vec = v;
	float len = length(v);
	if (len != 0)
	{
		vec.x /= len;
		vec.y /= len;
	}
	return vec;
}

static float lerp(float start, float end, float percent)
{
	return(start + percent * (end - start));
}

template <typename T>
static vec2<T> lerp(const vec2<T>& start, const vec2<T>& end, float percent)
{
	return(start + (end - start) * percent);
}

using vec2i = vec2<int>;
using vec2f = vec2<float>;

#endif
