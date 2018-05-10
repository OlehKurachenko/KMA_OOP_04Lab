//
//  Created by Oleh Kurachenko
//         aka okurache
//  on 2018-02-02T12:08:53Z as a part of KMA_OOP_02Lab
//
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//
#include "Segment.h"

unsigned Segment::freeID = 0;

std::ostream& operator<<(std::ostream &ostr, const Segment &segment) {
	return ostr << "Segment{start=" << segment.start() << ",end=" << segment.end() << ",ID="
				<< segment.getID() << "}";
}

double Segment::distance(const Point &point) const {
	double a(this->end().y() - this->start().y());
	double b(this->start().x() - this->end().x());
	double c(this->start().y() * this->end().x() - this->start().x() * this->end().y());
	double distanceToLine((a * point.x() + b * point.y() + c) / sqrt(a * a + b * b));
	double dToStart(this->start().distanceTo(point));
	double dToEnd(this->end().distanceTo(point));
	double maxInnerLen(sqrt(distanceToLine * distanceToLine + pow(this->length(), 2)));
	double minDistance = std::min(dToStart, dToEnd);

	if (dToStart < maxInnerLen && dToEnd < maxInnerLen)
		minDistance = std::min(minDistance, distanceToLine);
	return minDistance;
}
