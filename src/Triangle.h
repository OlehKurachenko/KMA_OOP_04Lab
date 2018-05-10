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
    Triangle(const double x1=0, const double y1=0,
             const double x2=1, const double y2=0,
             const double x3=0, const double y3=1);

    Triangle(const Point &a, const Point& b, const Point& c);

    Triangle(const Point &a, const Segment &_bc);

    Triangle (const Triangle&);

    ~Triangle();

    Triangle& operator=(const Triangle&);

    double perimeter() const;

    double area() const;

    Point& apexA();

    Point& apexB();

    Point& apexC();

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

#endif //KMA_OOP_04LAB_TRIANGLE_H
