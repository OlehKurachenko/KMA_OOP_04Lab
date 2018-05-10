//
//  Created by Oleh Kurachenko
//         aka okurache
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#ifndef KMA_OOP_01LAB_POINT_H
#define KMA_OOP_01LAB_POINT_H

#include <iostream>
#include <cmath>

class Point {
public:
	explicit inline Point(double x = 0, double y = 0);

	inline Point(const Point &that);

	inline ~Point();

	inline Point& operator=(const Point &that);

	inline double& x() { return this->_x; }

	inline double& y() { return this->_y; }

	inline const double& x() const { return this->_x; }

	inline const double& y() const { return this->_y; }

	inline double distanceTo(const Point &that) const;

	inline const int getID() const { return this->_pointID; }

	inline static const int amount() { return freeID; }

private:

	double _x;
	double _y;
	static unsigned int freeID;
	const unsigned int _pointID;
};

inline std::ostream& operator<<(std::ostream &, const Point&);

inline Point& operator+=(Point&, const Point&);

inline Point operator+(const Point &u, const Point &v);

inline Point& operator-=(Point&, const Point&);

inline Point operator-(const Point &u, const Point &v);

inline bool operator==(const Point &one, const Point &another);

inline bool operator!=(const Point &one, const Point &another) { return !(one == another); }

//  Definitions of class Point methods

inline Point::Point(double x, double y):
    _x(x),
    _y(y),
    _pointID(++freeID)
{
#ifndef NDEBUG
    std::cout << "constructor Point(" << x << ", " << y << ") call, point ID"
              << _pointID << " created" << std::endl;
#endif
}

inline Point::Point(const Point &that):
    _x(that._x),
    _y(that._y),
    _pointID(++freeID)
{
#ifndef NDEBUG
    std::cout << "constructor Point(" << that << ") call, point ID"
              << _pointID << " created" << std::endl;
#endif
}

inline Point::~Point() {
#ifndef NDEBUG
    std::cout << "destructor " << *this << " call" << std::endl;
#endif
}

inline Point& Point::operator=(const Point &that) {
    this->_x = that._x;
    this->_y = that._y;
    return *this;
}

inline double Point::distanceTo(const Point &that) const {
    return sqrt(pow(this->x() - that.x(), 2) + pow(this->y() - that.y(), 2));
}

//  Definitions of class Point utils

inline Point& operator+=(Point &one, const Point &another) {
    one.x() += another.x();
    one.y() += another.y();
    return one;
}

inline Point operator+(const Point &u, const Point &v) {
    Point t(u);
    return (t+=v);
}

inline Point& operator-=(Point &one, const Point &another) {
    one.x() -= another.x();
    one.y() -= another.y();
    return one;
}

inline Point operator-(const Point &u, const Point &v) {
    Point t(u);
    return (t-=v);
}

inline bool operator==(const Point &one, const Point &another) {
    if (one.x() != another.x())
        return false;
    return (one.y() == another.y());
}

inline std::ostream& operator<<(std::ostream &ostr, const Point &point) {
    ostr << "Point{x=" << point.x() << ",y=" << point.y() << ",ID=" << point.getID() << '}';
    return ostr;
}

#endif //KMA_OOP_01LAB_POINT_H
