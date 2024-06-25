/**

 */
#pragma once
#include "Point.hpp"

// Line2 dim
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

using Line2i = _Line2<int>;
using Line2f = _Line2<float>;
using Line2d = _Line2<double>;