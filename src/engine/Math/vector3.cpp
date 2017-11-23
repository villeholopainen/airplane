#include "vector3.h"

Vector3::Vector3()
{
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

Vector3::Vector3(const Vector3 &other)
{
    m_x = other.m_x;
    m_y = other.m_y;
    m_z = other.m_z;
}

Vector3::Vector3(float x)
{
    m_x = x;
    m_y = x;
    m_z = x;
}

Vector3::Vector3(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

Vector3 &Vector3::operator=(const Vector3 &other)
{
    m_x = other.m_x;
    m_y = other.m_y;
    m_z = other.m_z;
    return *this;
}

Vector3 Vector3::operator+(const Vector3 &other)
{
    Vector3 vec;
    vec.m_x = m_x + other.m_x;
    vec.m_y = m_y + other.m_y;
    vec.m_z = m_z + other.m_z;
    return vec;
}

Vector3 Vector3::operator-(const Vector3 &other)
{
    Vector3 vec;
    vec.m_x = m_x - other.m_x;
    vec.m_y = m_y - other.m_y;
    vec.m_z = m_z - other.m_z;
    return vec;
}

Vector3 Vector3::operator*(const Vector3 &other)
{
    Vector3 vec;
    vec.m_x = m_x * other.m_x;
    vec.m_y = m_y * other.m_y;
    vec.m_z = m_z * other.m_z;
    return vec;
}

Vector3 Vector3::operator*(float x)
{
    Vector3 vec;
    vec.m_x = m_x * x;
    vec.m_y = m_y * x;
    vec.m_z = m_z * x;
    return vec;
}

bool Vector3::operator==(const Vector3 &other)
{
    return (m_x == other.m_x &&
            m_y == other.m_y &&
            m_z == other.m_z);
}

bool Vector3::operator!=(const Vector3 &other)
{
    return !operator==(other);
}
