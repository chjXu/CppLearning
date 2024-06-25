/**

 */
#pragma once

#include <iostream>
#include <cmath>

struct PixelPoint
{
    float u;
    float v;
};

struct WorldPoint
{
    float x;
    float y;
    float z;
};

/****************************************** Point2D **************************************************/
// Point2 dim
template<typename _Tp>
class _Point2
{
public:
    typedef _Tp value_type;

    _Point2();
    _Point2(_Tp x, _Tp y);
    _Point2(const _Point2& pt);
    // _Point2(const _Tp& x, const _Tp& y); // ambiguous with _Point2(_Tp x, _Tp y);

    _Point2& operator=(const _Point2& pt);
    _Point2 operator-(const _Point2& pt);

    value_type x() const;
    value_type y() const;

    template<typename _Tp2>
    void copyFrom(const _Tp2& pt);

    void copyFrom(const PixelPoint& pt);

    bool isZero() const;
private:
    _Tp _x;
    _Tp _y;
};

template<typename _Tp> inline
_Point2<_Tp>::_Point2() : _x(_Tp(0)), _y(_Tp(0)) {}

template<typename _Tp> inline
_Point2<_Tp>::_Point2(_Tp x, _Tp y) : _x(x), _y(y) {}

template<typename _Tp> inline
_Point2<_Tp>::_Point2(const _Point2& pt) : _x(pt._x), _y(pt._y) {}

// template<typename _Tp> inline
// _Point2<_Tp>::_Point2(const _Tp& x, const _Tp& y) : _x(x), _y(y) {}

template<typename _Tp> inline
_Point2<_Tp>& _Point2<_Tp>::operator=(const _Point2& pt)
{
    _x = pt._x;
    _y = pt._y;
    return *this;
}

template<typename _Tp> inline
_Point2<_Tp> _Point2<_Tp>::operator-(const _Point2& pt)
{
    return _Point2<_Tp>(_x - pt._x, _y - pt._y);
}

template<typename _Tp> inline
_Tp _Point2<_Tp>::x() const { return this->_x; }

template<typename _Tp> inline
_Tp _Point2<_Tp>::y() const { return this->_y; }

template<typename _Tp>
template<typename _Tp2>
void _Point2<_Tp>::copyFrom(const _Tp2& pt)
{
    _x = pt.x();
    _y = pt.y();
}

template<typename _Tp>
void _Point2<_Tp>::copyFrom(const PixelPoint& pt)
{
    _x = pt.u;
    _y = pt.v;
}

template<typename _Tp>
bool _Point2<_Tp>::isZero() const
{
    return std::fabs(_x - _Tp(0)) < 1e-4 &&  std::fabs(_y - _Tp(0)) < 1e-4;
}
using Point2i = _Point2<int>;
using Point2f = _Point2<float>;
using Point2d = _Point2<double>;
/*****************************************************************************************************/

/****************************************** Point3D **************************************************/
// Point3 dim
template<typename _Tp>
class _Point3
{
public:
    typedef _Tp value_type;

    _Point3();
    _Point3(_Tp x, _Tp y, _Tp z);
    _Point3(const _Point3& pt);

    _Point3& operator=(const _Point3& pt);
    _Point3 operator-(const _Point3& pt);

    value_type x() const;
    value_type y() const;
    value_type z() const;

    template<typename _Tp2>
    void copyFrom(const _Tp2& pt);

    void copyFrom(const WorldPoint& pt);

    bool isZero() const;
private:
    _Tp _x;
    _Tp _y;
    _Tp _z;
};

template<typename _Tp> inline
_Point3<_Tp>::_Point3() : _x(_Tp(0)), _y(_Tp(0)), _z(_Tp(0)) {}

template<typename _Tp> inline
_Point3<_Tp>::_Point3(_Tp x, _Tp y, _Tp z) : _x(x), _y(y), _z(z) {}

template<typename _Tp> inline
_Point3<_Tp>::_Point3(const _Point3& pt) : _x(pt._x), _y(pt._y), _z(pt._z) {}

// template<typename _Tp> inline
// _Point3<_Tp>::_Point3(const _Tp& x, const _Tp& y, const _Tp& z) : _x(x), _y(y), _z(z) {}

template<typename _Tp> inline
_Point3<_Tp>& _Point3<_Tp>::operator=(const _Point3& pt)
{
    _x = pt._x;
    _y = pt._y;
    _z = pt._z;
    return *this;
}

template<typename _Tp> inline
_Point3<_Tp> _Point3<_Tp>::operator-(const _Point3& pt)
{
    return _Point3<_Tp>(_x - pt._x, _y - pt._y, _z - pt._z);
}

template<typename _Tp> inline
_Tp _Point3<_Tp>::x() const { return this->_x; }

template<typename _Tp> inline
_Tp _Point3<_Tp>::y() const { return this->_y; }

template<typename _Tp> inline
_Tp _Point3<_Tp>::z() const { return this->_z; }

template<typename _Tp>
template<typename _Tp2>
void _Point3<_Tp>::copyFrom(const _Tp2& pt)
{
    _x = pt.x();
    _y = pt.y();
    _z = pt.z();
}

template<typename _Tp>
void _Point3<_Tp>::copyFrom(const WorldPoint& pt)
{
    _x = pt.x;
    _y = pt.y;
    _z = pt.z;
}

template<typename _Tp>
bool _Point3<_Tp>::isZero() const
{
    return std::fabs(_x - _Tp(0)) < 1e-4 && std::fabs(_y - _Tp(0)) < 1e-4 && std::fabs(_z - _Tp(0)) < 1e-4;
}
using Point3i = _Point3<int>;
using Point3f = _Point3<float>;
using Point3d = _Point3<double>;