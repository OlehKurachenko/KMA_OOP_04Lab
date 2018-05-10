# KMA OOP 04Lab

A task form [OOP][Volodymyr Boublik] course in [NaUKMA][NaUKMA].

This task is based on [01Lab](src/Point/README_01Lab.md) and
[02Lab](src/Segment/README_02Lab.md)

[Volodymyr Boublik]: https://www.linkedin.com/in/volodymyr-boublik-869a4430/
[NaUKMA]: http://www.ukma.edu.ua/eng/

## Task

Implement and justify the most effective (in terms of creating
temporary objects) class Triangle using its vertices and (or)
segments.

```cpp
Point _a, _b, _c;
Segment _ab, _bc, _ca;
Point &_a, &_b, &_c;
Segment &_ab, &_bc, &_ca;
Point *_a, *_b, *_c;
Segment *_ab, *_bc, *_ca; 
```

Keep track of points and segments.  
Do not forget about compatibility.

```cpp
class Point;

class Segment;

class Triangle {

private:

//  ???

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

};

ostream& operator<<(ostream &, const Triangle &);
```