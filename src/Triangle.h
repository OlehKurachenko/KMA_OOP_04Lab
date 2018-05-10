// 
//  Created by Oleh Kurachenko
//         aka okurache
//  on 2018-05-10T17:24:41Z as a part of KMA_OOP_04Lab
//  
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#ifndef KMA_OOP_04LAB_TRIANGLE_H
#define KMA_OOP_04LAB_TRIANGLE_H

#include <iostream>
#include <string>
#include <cmath>

#include "Point/Point.h"
#include "Segment/Segment.h"

using namespace std;

class Triangle {
public:
    class BadTriangle;

    explicit inline Triangle(const double x1=0, const double y1=0,
             const double x2=1, const double y2=0,
             const double x3=0, const double y3=1);

    inline Triangle(const Point &a, const Point& b, const Point& c);

    inline Triangle(const Point &a, const Segment &bc);

    inline Triangle (const Triangle&);

    inline ~Triangle();

    inline Triangle& operator=(const Triangle&);

    inline double perimeter() const { return _a.distanceTo(_b) + _b.distanceTo(_c) + _c.distanceTo(_a); }

    inline double area() const;

    inline const Point& apexA() const { return _a; }

    inline const Point& apexB() const { return _b; }

    inline const Point& apexC() const { return _c; }

    inline const Segment& side_a() const;

    inline const Segment& side_b() const;

    inline const Segment& side_c() const;

    inline double length_a() const { return _b.distanceTo(_c); }

    inline double length_b() const { return _a.distanceTo(_c); }

    inline double length_c() const { return _a.distanceTo(_b); }

    inline const Segment& height_a() const;

    inline const Segment& height_b() const;

    inline const Segment& height_c() const;

private:

    Point _a, _b, _c;
    mutable Segment *_ab, *_bc, *_ac;
    mutable Segment *_ha, *_hb, *_hc;

    /**
     * @param top -- vertex-top of height
     * @param baseA -- first vertex of base of height
     * @param baseB -- second vertex of base of height
     * @return height form vertex top to base
     */
    inline static Segment height(const Point &top, const Point &baseA, const Point &baseB);
};

//  class Triangle utills declarations

inline ostream& operator<<(ostream &, const Triangle &);


//  class Triangle::BadTriangle body & utills

class Triangle::BadTriangle {
public:
    inline BadTriangle(const string &errorMessage):
        _errorMessage(errorMessage) { }

    string _errorMessage;
};

inline ostream& operator<<(ostream &ostr, const Triangle::BadTriangle &badTriangle) {
    ostr << "BadTriangle: " << badTriangle._errorMessage << endl;
    return ostr;
}

//  class Triangle methods definitions

inline Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3,
                   const double y3):
    _a(x1, y1),
    _b(x2, y2),
    _c(x3, y3),
    _ab(NULL),
    _bc(NULL),
    _ac(NULL),
    _ha(NULL),
    _hb(NULL),
    _hc(NULL)
{
    if (this->area() == 0)
        throw BadTriangle("area is 0");
#ifndef NDEBUG
    cout << "constructor Triangle(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3
         << ", " << y3 << ") call, " << *this << " created" << endl;
#endif
}

inline Triangle::Triangle(const Point &a, const Point &b, const Point &c):
        _a(a),
        _b(b),
        _c(c),
        _ab(NULL),
        _bc(NULL),
        _ac(NULL),
        _ha(NULL),
        _hb(NULL),
        _hc(NULL)
{
    if (this->area() == 0)
        throw BadTriangle("area is 0");
#ifndef NDEBUG
    cout << "constructor Triangle(" << a << ", " << b << ", " << c << ") call, " << *this << " created" << endl;
#endif
}

inline Triangle::Triangle(const Point &a, const Segment &bc):
        _a(a),
        _b(bc.start()),
        _c(bc.end()),
        _ab(NULL),
        _bc(NULL),
        _ac(NULL),
        _ha(NULL),
        _hb(NULL),
        _hc(NULL)
{
    if (this->area() == 0)
        throw BadTriangle("area is 0");
#ifndef NDEBUG
    cout << "constructor Triangle(" << a << ", " << bc << ") call, " << *this << " created" << endl;
#endif
}

inline Triangle::Triangle(const Triangle &that):
        _a(that.apexA()),
        _b(that.apexB()),
        _c(that.apexC()),
        _ab(NULL),
        _bc(NULL),
        _ac(NULL),
        _ha(NULL),
        _hb(NULL),
        _hc(NULL)
{
#ifndef NDEBUG
    cout << "constructor Triangle(" << that << ") call, " << *this << " created" << endl;
#endif
}

inline Triangle::~Triangle() {
#ifndef NDEBUG
    cout << "destructor ~Triangle(" << *this  << ") call" << endl;
#endif
    delete _ab;
    delete _bc;
    delete _ac;
    delete _ha;
    delete _hb;
    delete _hc;
}

inline Triangle &Triangle::operator=(const Triangle &that) {
    _a = that.apexA();
    _b = that.apexB();
    _c = that.apexC();
    _ab = NULL;
    _bc = NULL;
    _ac = NULL;
    _ha = NULL;
    _hb = NULL;
    _hc = NULL;
    return *this;
}

inline double Triangle::area() const {
    return abs((apexB().x() - apexA().x()) * (apexC().y() - apexA().y())
           - (apexB().y() - apexA().y()) * (apexC().x() - apexA().x())) / 2;
}

inline const Segment& Triangle::side_a() const {
    if (!_bc)
        _bc = new Segment(_b, _c);
    return *_bc;
}

inline const Segment &Triangle::side_b() const {
    if (!_ac)
        _ac = new Segment(_a, _c);
    return *_ac;
}

inline const Segment &Triangle::side_c() const {
    if (!_ab)
        _ab = new Segment(_a, _b);
    return *_ab;
}

inline const Segment &Triangle::height_a() const {
    if (!_ha)
        _ha = new Segment(height(_a, _b, _c));
    return *_ha;
}

inline const Segment &Triangle::height_b() const {
    if (!_hb)
        _hb = new Segment(height(_b, _a, _c));
    return *_hb;
}

inline const Segment &Triangle::height_c() const {
    if (!_hc)
        _hc = new Segment(height(_c, _a, _b));
    return *_hc;
}

inline Segment Triangle::height(const Point &top, const Point &baseA, const Point &baseB) {
    const double a = baseB.y() - baseA.y();   // A in base line equation and B in equation of height line
    const double b = baseA.x() - baseB.x();   // B in base line equation and -A in equation of height line
    const double c = baseB.x() * baseA.y() - baseA.x() * baseB.y(); // C in base line equation
    const double ch = top.x() * (baseA.x() - baseB.x()) - top.y() * (baseB.y() - baseA.y());    // C in equation
                                                                                                // of height line

    if (a == 0)
        return Segment(top, Point(ch / b, -(c / b)));

    const double y = -((b * c / a + ch) / (a + b * b / a));
    return Segment(top, Point(-((b * y + c) / a), y));
}

//  class Triangle utills definitions

inline ostream& operator<<(ostream &ostr, const Triangle &triangle) {
    ostr << "Triangle{a=" << triangle.apexA() << ", b=" << triangle.apexB() << ", c=" << triangle.apexC() << '}';
    return ostr;
}

#endif //KMA_OOP_04LAB_TRIANGLE_H
