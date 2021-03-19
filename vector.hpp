#ifndef __HEDS_VECTOR_HPP__
#define __HEDS_VECTOR_HPP__

#include <iostream>
#include <cmath>

class Vector
{

public:

    double x;
    double y;
    double z;

    Vector() : Vector(0, 0, 0) {}
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    double& operator[](int idx)
    {
        idx %= 3;
        if (idx == 0) return x;
        else if (idx == 1) return y;
        else return z;
    }

    double operator[](int idx) const
    {
        return operator[](idx);
    }

    Vector operator+() const
    {
        Vector w;
        return w += *this;
    }

    Vector operator-() const
    {
        Vector w;
        return w -= *this;
    }
    
    Vector& operator+=(const Vector& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Vector& operator-=(const Vector& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Vector& operator*=(double rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    Vector& operator/=(double rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    double sqr_norm() const
    {
        return x*x + y*y + z*z;
    }

    double norm() const
    {
        return std::sqrt(sqr_norm());
    }
};

bool operator==(const Vector& lhs, const Vector& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}

bool operator!=(const Vector& lhs, const Vector& rhs)
{
    return !operator==(lhs, rhs);
}

Vector operator+(Vector lhs, const Vector& rhs)
{
    return lhs += rhs;
}

Vector operator-(Vector lhs, const Vector& rhs)
{
    return lhs -= rhs;
}

Vector operator*(double c, const Vector& v)
{
    Vector w(v);
    return w *= c;
}

Vector operator*(const Vector& v, double c)
{
    Vector w(v);
    return w *= c;
}

Vector operator/(const Vector& v, double c)
{
    Vector w(v);
    return w /= c;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

std::istream& operator>>(std::istream& is, Vector& v)
{
    return is >> v.x >> v.y >> v.z;
}

double dot(const Vector& lhs, const Vector& rhs)
{
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

Vector cross(const Vector& lhs, const Vector& rhs)
{
    return Vector
    (
        lhs.y*rhs.z - lhs.z*rhs.y,
        lhs.z*rhs.x - lhs.x*rhs.z,
        lhs.x*rhs.y - lhs.y*rhs.x
    );
}

double det(const Vector& u, const Vector& v, const Vector& w)
{
    return dot(u, cross(v, w));
}

#endif // __HEDS_VECTOR_HPP__

