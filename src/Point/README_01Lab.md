# KMA OOP 01Lab

A task form [OOP][Volodymyr Boublik] course in [NaUKMA][NaUKMA].

[Volodymyr Boublik]: https://www.linkedin.com/in/volodymyr-boublik-869a4430/
[NaUKMA]: http://www.ukma.edu.ua/eng/

## Task

Implement and test class Point:

```cpp
#ifndef _POINT_H_

#define _POINT_H_

#include <iostream>

using namespace std;

class Point {

private:

    static int freeID;

    const int pointID;

    double _x;

    double _y;

public:

    Point (double x=0, double y=0);

    Point (const Point &);

    ~Point();

    Point& operator=(const Point &);

    double& x();

    double& y();

    const double& x()const;

    const double& y()const;

    const int getID() const;

    static int amount();

};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point & u, const Point & v);

Point& operator+=(Point &, const Point&);

bool operator==(const Point & u, const Point &v);

bool operator!=(const Point & u, const Point &v);

#endif
```