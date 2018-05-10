// 
//  Created by Oleh Kurachenko
//         aka okurache
//  on 2018-05-10T13:00:32Z as a part of KMA_OOP_04Lab
//  
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#include <iostream>
#include <cassert>

#include "Triangle.h"

int main() {

    Triangle a;

    const Triangle b(10, 10, 20, 20, 30, 20);

    Triangle b2(b.apexA(), b.apexB(), b.apexC());

    Triangle b3(b.apexA(), Segment(b.apexB(), b.apexC()));

    const Triangle b4(b2);

    assert(a.apexA() == Point(0, 0));
    assert(a.apexB() == Point(1, 0));
    assert(a.apexC() == Point(0, 1));

    assert(b.apexA() == Point(10, 10));
    assert(b.apexB() == Point(20, 20));
    assert(b.apexC() == Point(30, 20));

    assert(b2.apexA() == Point(10, 10));
    assert(b2.apexB() == Point(20, 20));
    assert(b2.apexC() == Point(30, 20));

    assert(b3.apexA() == Point(10, 10));
    assert(b3.apexB() == Point(20, 20));
    assert(b3.apexC() == Point(30, 20));

    assert(b4.apexA() == Point(10, 10));
    assert(b4.apexB() == Point(20, 20));
    assert(b4.apexC() == Point(30, 20));

    assert(b2.side_a().start() == Point(20, 20));
    assert(b2.side_a().end() == Point(30, 20));

    assert(b.side_a().start() == Point(20, 20));
    assert(b.side_a().end() == Point(30, 20));

    cout.precision(5);

    cout << "\033[1;34m" << b2 << "\033[0;0m" << endl;
    cout << "\033[1;34m" << b2.height_a() << "\033[0;0m" << endl;
    cout << "\033[1;34m" << b2.height_b() << "\033[0;0m" << endl;
    cout << "\033[1;34m" << b2.height_c() << "\033[0;0m" << endl;

    assert(b2.height_a().end() == Point(10, 20));
    assert(b2.height_b().end() == Point(22, 16));
    assert(b2.height_c().end() == Point(25, 25));

    cout << "\033[1;34m" << b.side_b() << "\033[0;0m" << endl;
    cout << "\033[1;34m" << b.side_c() << "\033[0;0m" << endl;
    cout << "\033[1;34m" << b.side_b() << "\033[0;0m" << endl;
    cout << "\033[1;34m" << b.side_c() << "\033[0;0m" << endl;

    assert(b3.side_a().length() == b3.length_a());
    assert(b3.side_b().length() == b3.length_b());
    assert(b3.side_c().length() == b3.length_c());

    Triangle c(0, 0, 0, 4, 3, 0);

    assert(c.perimeter() == 12);
    assert(c.area() == 6);

    cout << "\033[1;32m" << "tests: all ok!" << "\033[0;0m" << endl;

    try {
        Triangle d(0, 0, 0, 0, 0, 0);
    } catch (Triangle::BadTriangle &badTriangle) {
        cerr << badTriangle << endl;
    }

    return 0;
}
