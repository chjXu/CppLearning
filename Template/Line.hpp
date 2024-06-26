/**

 */
#pragma once
#include "Point.hpp"

/************************************* Line 2D **********************************************/
template<typename _Tp>
class _Line2
{
public:
    typedef _Tp value_type;

    _Line2();
    _Line2(_Point2<_Tp> pt1, _Point2<_Tp> pt2);
    _Line2(const _Line2<_Tp>& l);
    _Line2& operator=(const _Line2& l);

    _Point2<_Tp> sp() const;    // start point
    _Point2<_Tp> ep() const;    // end point
    _Point2<_Tp> vd() const;    // vector direct

    bool isZero() const;

    /**
     * @param pt1 : start point
     * @param pt2 : end point
     * @return void
     */
    void set(_Point2<_Tp> pt1, _Point2<_Tp> pt2);
private:
    _Point2<_Tp> _pt1;
    _Point2<_Tp> _pt2;
    _Point2<_Tp> _v;
};

template<typename _Tp> inline
_Line2<_Tp>::_Line2() : _pt1(_Point2<_Tp>(0, 0)), _pt2(_Point2<_Tp>(0, 0)), _v(_pt2 - _pt1) {}

template<typename _Tp> inline
_Line2<_Tp>::_Line2(_Point2<_Tp> pt1, _Point2<_Tp> pt2) : _pt1(pt1), _pt2(pt2), _v(_pt2 - _pt1) {}

template<typename _Tp> inline
_Line2<_Tp>::_Line2(const _Line2& l) : _pt1(l._pt1), _pt2(l._pt2), _v(l._pt2 - l._pt1) {}

template<typename _Tp> inline
_Line2<_Tp>& _Line2<_Tp>::operator=(const _Line2& l)
{
    _pt1 = l._pt1;
    _pt2 = l._pt2; 
    _v = l._v;
    return *this;
}

template<typename _Tp> inline
_Point2<_Tp> _Line2<_Tp>::sp() const { return this->_pt1; }

template<typename _Tp> inline
_Point2<_Tp> _Line2<_Tp>::ep() const { return this->_pt2; }

template<typename _Tp> inline
_Point2<_Tp> _Line2<_Tp>::vd() const { return this->_v; }

template<typename _Tp> inline
bool _Line2<_Tp>::isZero() const
{
    return _pt1.isZero() && _pt2.isZero() && _v.isZero();
}

template<typename _Tp> inline
void _Line2<_Tp>::set(_Point2<_Tp> pt1, _Point2<_Tp> pt2)
{
    _pt1 = pt1;
    _pt2 = pt2;
    _v = pt2 - pt1;
}
using Line2i = _Line2<int>;
using Line2f = _Line2<float>;
using Line2d = _Line2<double>;
/********************************************************************************************/

/************************************* Line 2D **********************************************/
template<typename _Tp>
class _Line3
{
public:
    typedef _Tp value_type;

    // default construct
    _Line3();
    _Line3(_Point3<_Tp> pt1, _Point3<_Tp> pt2);
    _Line3(const _Line3<_Tp>& l);
    _Line3& operator=(const _Line3& l);

    _Point3<_Tp> sp() const;    // start point
    _Point3<_Tp> ep() const;    // end point
    _Point3<_Tp> vd() const;    // vector direct

    bool isZero() const;

    /**
     * @param pt1 : start point
     * @param pt2 : end point
     * @return void
     */
    void set(_Point3<_Tp> pt1, _Point3<_Tp> pt2);
private:
    _Point3<_Tp> _pt1;
    _Point3<_Tp> _pt2;
    _Point3<_Tp> _v;
};

template<typename _Tp> inline
_Line3<_Tp>::_Line3() : _pt1(_Point3<_Tp>(0, 0, 0)), _pt2(_Point3<_Tp>(0, 0, 0)), _v(_pt2 - _pt1) {}

template<typename _Tp> inline
_Line3<_Tp>::_Line3(_Point3<_Tp> pt1, _Point3<_Tp> pt2) : _pt1(pt1), _pt2(pt2), _v(_pt2 - _pt1) {}

template<typename _Tp> inline
_Line3<_Tp>::_Line3(const _Line3& l) : _pt1(l._pt1), _pt2(l._pt2), _v(l._pt2 - l._pt1) {}

template<typename _Tp> inline
_Line3<_Tp>& _Line3<_Tp>::operator=(const _Line3& l)
{
    _pt1 = l._pt1;
    _pt2 = l._pt2; 
    _v = l._v;
    return *this;
}

template<typename _Tp> inline
_Point3<_Tp> _Line3<_Tp>::sp() const { return this->_pt1; }

template<typename _Tp> inline
_Point3<_Tp> _Line3<_Tp>::ep() const { return this->_pt2; }

template<typename _Tp> inline
_Point3<_Tp> _Line3<_Tp>::vd() const { return this->_v; }

template<typename _Tp> inline
bool _Line3<_Tp>::isZero() const
{
    return _pt1.isZero() && _pt2.isZero() && _v.isZero();
}

template<typename _Tp> inline
void _Line3<_Tp>::set(_Point3<_Tp> pt1, _Point3<_Tp> pt2)
{
    _pt1 = pt1;
    _pt2 = pt2;
    _v = pt2 - pt1;
}
using Line3i = _Line3<int>;
using Line3f = _Line3<float>;
using Line3d = _Line3<double>;
/********************************************************************************************/