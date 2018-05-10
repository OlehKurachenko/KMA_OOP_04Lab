//
//  Created by Oleh Kurachenko
//         aka okurache
//  on 2018-02-02T12:08:54Z as a part of KMA_OOP_02Lab
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#ifndef KMA_OOP_02LAB_SEGMENT_H
#define KMA_OOP_02LAB_SEGMENT_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include "../Point/Point.h"

class Segment {
public:
	explicit inline Segment(const double x1 = 0, const double y1 = 0,
							const double x2 = 0, const double y2 = 0);

	explicit inline Segment(const Point &a, const Point &b = Point(0, 0));

	inline Segment(const Segment &that);

	inline ~Segment();

	inline Segment& operator=(const Segment& that);

	inline const Point& start() const { return this->_a; }

	inline const Point& end() const { return this->_b; }

	inline Point& start() { return this->_a; }

	inline Point& end() { return this->_b; }

	inline const double startX() const { return start().x(); }

	inline const double startY() const { return start().y(); }

	inline const double endX() const { return end().x(); }

	inline const double endY() const { return end().y(); }

	inline double& startX() { return start().x(); }

	inline double& startY() { return start().y(); }

	inline double& endX() { return end().x(); }

	inline double& endY() { return end().y(); }

	inline double length() const { return start().distanceTo(end()); }

	double distance(const Point&) const;

	inline const unsigned getID() const { return this->_myID; }

	inline static const int amount() { return freeID; }

private:
	static unsigned freeID;
	const unsigned _myID;
	Point _a;
	Point _b;
};

std::ostream& operator<<(std::ostream &ostr, const Segment &segment);

//  Definitions of class Segment methods

inline Segment::Segment(const double x1, const double y1, const double x2, const double y2):
    _myID(++freeID),
    _a(x1, y1),
    _b(x2, y2)
{
#ifndef NDEBUG
    std::cout << "constructor Segment(" << x1 << ", " << x2 << ", "
              << y1 << ", " << y2 << ", " << ") call, "
              << *this << " created" << std::endl;
#endif
}

inline Segment::Segment(const Point &a, const Point &b = Point(0, 0)):
    _myID(++freeID),
    _a(a),
    _b(b)
{
#ifndef NDEBUG
    std::cout << "constructor Segment(" << a << ", "
              << b << ", " << ") call, "
              << *this << " created" << std::endl;
#endif
}

inline Segment::Segment(const Segment &that):
    _myID(++freeID),
    _a(that._a),
    _b(that._b)
{
#ifndef NDEBUG
    std::cout << "constructor Segment(" << that << ", " << ") call, "
              << *this << " created" << std::endl;
#endif
}

inline Segment::~Segment() {
#ifndef NDEBUG
    std::cout << "destructor Segment(" << *this << ", " << ") call" << std::endl;
#endif
}

inline Segment& Segment::operator=(const Segment& that) {
    this->_a = that._a;
    this->_b = that._b;
    return *this;
}

#endif //KMA_OOP_02LAB_SEGMENT_H
