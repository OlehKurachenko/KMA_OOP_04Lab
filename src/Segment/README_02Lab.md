# KMA OOP 02Lab

A task form [OOP][Volodymyr Boublik] course in [NaUKMA][NaUKMA].

This task is based on [01Lab](../Point/README_01Lab.md)

[Volodymyr Boublik]: https://www.linkedin.com/in/volodymyr-boublik-869a4430/
[NaUKMA]: http://www.ukma.edu.ua/eng/

## Task

Implement and test class Segment:

```cpp

class Segment {

private:

    static int _freeID;

    const int _myId;

    Point _a;

    Point _b;

public:

    Segment(const double x1=0, const double y1=0,
        const double x2=1, const double y2=0);


    Segment(const Point &start, const Point &end);

    Segment(const Segment&);

    ~Segment();

    Segment& operator=(const Segment&);

    const Point& start() const;

    const Point& end() const;

    Point &Segment::start();

    Point &Segment::end();

    const double &Segment::startX() const;

    const double &Segment::startY() const;

    const double &Segment::endX() const;

    const double &Segment::endY() const;

    double &Segment::startX();

    double &Segment::startY();

    double &Segment::endX();

    double &Segment::endY();

    double length () const;

    double distance (const Point&) const;

    const int getID() const;

};

ostream& operator<<(ostream &, const Segment &);
```
