#ifndef rect_hpp
#define rect_hpp

template <typename T>
struct Rect
{
    T x;
    T y;
    T w;
    T h;

    Rect() {}
    Rect(T _x, T _y, T _w, T _h)
    {
        x = _x;
        y = _y;
        w = _w;
        h = _h;
    }

    template <typename U>
    auto& operator=(const Rect<U>& other)
    {
        x = static_cast<T>(other.x);
        y = static_cast<T>(other.y);
        w = static_cast<T>(other.w);
        h = static_cast<T>(other.h);

        return *this;
    }
};

using Rectf = Rect<float>;
using Recti = Rect<int>;

#endif
