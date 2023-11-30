//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_VECTOR2_H
#define INC_2CCPP_PROJECT_VECTOR2_H

/**
 * @brief Represents a 2D vector.
 *
 * The Vec2 class provides a template for a 2D vector with basic mathematical operations.
 *
 * @tparam T The type of the vector components.
 */
template <typename T>
class Vec2 {

private:
    T x;
    T y;

public:

    /**
     * @brief Default constructor for Vec2.
     */
    Vec2() = default;

    /**
     * @brief Parameterized constructor for Vec2.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    constexpr Vec2(T x, T y) : x(x), y(y){};

    /**
     * @brief Gets the x-coordinate.
     *
     * @return The x-coordinate.
     */
    T GetX() const {return x;};

    /**
     * @brief Gets the y-coordinate.
     *
     * @return The y-coordinate.
     */
    T GetY() const {return y;};

    /**
     * @brief Sets the x-coordinate.
     *
     * @param value The new value for the x-coordinate.
     */
    void SetX(T value) { x = value;}

    /**
     * @brief Sets the y-coordinate.
     *
     * @param value The new value for the y-coordinate.
     */
    void SetY(T value) { y = value;}


    // Operators overloading
    /**
     * @brief Equality comparison operator.
     *
     * @param other The vector to compare.
     * @return True if the vectors are equal, false otherwise.
     */
    bool operator==(const Vec2& other) const
    {
        return (x == other.x && y == other.y);
    }

    /**
     * @brief Inequality comparison operator.
     *
     * @param other The vector to compare.
     * @return True if the vectors are not equal, false otherwise.
     */
    bool operator!=(const Vec2& other) const
    {
        return !(*this == other);
    }

    /**
     * @brief Addition operator for vectors.
     *
     * @param other The vector to add.
     * @return The result of the addition.
     */
    Vec2 operator+(const Vec2& other) const
    {
        return {x + other.x, y + other.y};
    }

    /**
     * @brief Addition operator for a scalar value.
     *
     * @param other The scalar value to add.
     * @return The result of the addition.
     */
    Vec2 operator+(const int other) const
    {
        return {x + other, y + other};
    }

    /**
     * @brief Compound addition operator for vectors.
     *
     * @param other The vector to add.
     * @return Reference to the modified vector.
     */
    Vec2& operator+=(const Vec2& other)
    {
        return *this = *this + other;
    }

    /**
     * @brief Subtraction operator for vectors.
     *
     * @param other The vector to subtract.
     * @return The result of the subtraction.
     */
    Vec2 operator-(const Vec2& other) const
    {
        return {x - other.x, y - other.y};
    }

    /**
     * @brief Subtraction operator for a scalar value.
     *
     * @param other The scalar value to subtract.
     * @return The result of the subtraction.
     */
    Vec2 operator-(const int other) const
    {
        return {x - other, y - other};
    }

    /**
     * @brief Compound subtraction operator for vectors.
     *
     * @param other The vector to subtract.
     * @return Reference to the modified vector.
     */
    Vec2& operator-=(const Vec2& other)
    {
        return *this = *this - other;
    }

    /**
     * @brief Multiplication operator for vectors.
     *
     * @param other The vector to multiply.
     * @return The result of the multiplication.
     */
    Vec2 operator*(const Vec2& other) const
    {
        return {x * other.x, y * other.y};
    }

    /**
     * @brief Multiplication operator for a scalar value.
     *
     * @param other The scalar value to multiply.
     * @return The result of the multiplication.
     */
    Vec2 operator*(const int other) const
    {
        return {x * other, y * other};
    }

    /**
     * @brief Compound multiplication operator for vectors.
     *
     * @param other The vector to multiply.
     * @return Reference to the modified vector.
     */
    Vec2& operator*=(const Vec2& other)
    {
        return *this = *this * other;
    }

    /**
     * @brief Division operator for vectors.
     *
     * @param other The vector to divide by.
     * @return The result of the division.
     */
    Vec2 operator/(const Vec2& other) const
    {
        return {x / other.x, y / other.y};
    }

    /**
     * @brief Division operator for a scalar value.
     *
     * @param other The scalar value to divide by.
     * @return The result of the division.
     */
    Vec2 operator/(const int other) const
    {
        return {x / other, y / other};
    }

    /**
     * @brief Compound division operator for vectors.
     *
     * @param other The vector to divide by.
     * @return Reference to the modified vector.
     */
    Vec2& operator/=(const Vec2& other)
    {
        return *this = *this / other;
    }

    /**
     * @brief Modulo operator for vectors with integer components.
     *
     * @param other The vector with integer components to perform modulo operation with.
     * @return The result of the modulo operation.
     */
    Vec2 operator%(const Vec2<int> other) const
    {
        return {x % other.GetX(), y % other.GetY()};
    }

    // Similar operator overloads for subtraction, multiplication, division, modulos, and comparison operators...
    Vec2 operator%(const int other) const
    {
        return {x % other, y % other};
    }


    Vec2& operator%=(const Vec2& other)
    {
        return *this = *this % other;
    }


    // > and < and <= and >=
    bool operator<(const Vec2<int> other) const
    {
        return x < other.GetX() && y < other.GetY();
    }


    bool operator>(const Vec2<int> other) const
    {
        return x > other.GetX() && y > other.GetY();
    }


    bool operator<=(const Vec2<int> other) const
    {
        return x <= other.GetX() && y <= other.GetY();
    }


    bool operator>=(const Vec2<int> other) const
    {
        return x >= other.GetX() && y >= other.GetY();
    }



};


#endif //INC_2CCPP_PROJECT_VECTOR2_H
