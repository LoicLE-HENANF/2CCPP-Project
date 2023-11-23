//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_VECTOR2_H
#define INC_2CCPP_PROJECT_VECTOR2_H

template <typename T>
class Vec2 {
public:
    Vec2() = default;
    constexpr Vec2(T x, T y) : x(x), y(y){};

    T GetX() const {return x;};
    T GetY() const {return y;};

    void SetX(T value) { x = value;}
    void SetY(T value) { y = value;}

private:
    T x;
    T y;

    // Operator overloading
public:
    bool operator==(const Vec2& other) const
    {
        return (x == other.x && y == other.y);
    }
    bool operator!=(const Vec2& other) const
    {
        return !(*this == other);
    }
    Vec2 operator+(const Vec2& other) const
    {
        return {x + other.x, y + other.y};
    }
    Vec2 operator+(const int other) const
    {
        return {x + other, y + other};
    }
    Vec2& operator+=(const Vec2& other)
    {
        return *this = *this + other;
    }
    Vec2 operator-(const Vec2& other) const
    {
        return {x - other.x, y - other.y};
    }
    Vec2 operator-(const int other) const
    {
        return {x - other, y - other};
    }
    Vec2& operator-=(const Vec2& other)
    {
        return *this = *this - other;
    }
    Vec2 operator*(const Vec2& other) const
    {
        return {x * other.x, y * other.y};
    }
    Vec2 operator*(const int other) const
    {
        return {x * other, y * other};
    }
    Vec2& operator*=(const Vec2& other)
    {
        return *this = *this * other;
    }

    Vec2 operator/(const Vec2& other) const
    {
        return {x / other.x, y / other.y};
    }
    Vec2 operator/(const int other) const
    {
        return {x / other, y / other};
    }
    Vec2& operator/=(const Vec2& other)
    {
        return *this = *this / other;
    }
    Vec2 operator%(const Vec2<int> other) const
    {
        return {x % other.GetX(), y % other.GetY()};
    }
    Vec2 operator%(const int other) const
    {
        return {x % other, y % other};
    }
    Vec2& operator%=(const Vec2& other)
    {
        return *this = *this % other;
    }



};


#endif //INC_2CCPP_PROJECT_VECTOR2_H
