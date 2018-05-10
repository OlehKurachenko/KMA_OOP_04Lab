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

#include "Point/Point.h"
#include "Segment/Segment.h"

using namespace std;

class Triangle {
public:
    explicit inline Triangle(const double x1=0, const double y1=0,
             const double x2=1, const double y2=0,
             const double x3=0, const double y3=1);

    inline Triangle(const Point &a, const Point& b, const Point& c);

    inline Triangle(const Point &a, const Segment &bc);

    inline Triangle (const Triangle&);

    inline ~Triangle();

    Triangle& operator=(const Triangle&);

    double perimeter() const;

    double area() const;

    const Point& apexA() const;

    const Point& apexB() const;

    const Point& apexC() const;

    const Segment& side_a() const;

    const Segment& side_b() const;

    const Segment& side_c() const;

    double length_a() const;

    double length_b() const;

    double length_c() const;

    const Segment& height_a() const;

    const Segment& height_b() const;

    const Segment& height_c() const;

private:

    Point _a, _b, _c;
    mutable Segment *_ab, *_bc, *_ac;
    mutable Segment *_ha, *_hb, *_hc;
};

inline ostream& operator<<(ostream &, const Triangle &); // TODO implement

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
    cout << "constructor ~Triangle(" << *this  << ") call" << endl;
#endif
    delete _ab;
    delete _bc;
    delete _ac;
    delete _ha;
    delete _hb;
    delete _hc;
}

#endif //KMA_OOP_04LAB_TRIANGLE_H
