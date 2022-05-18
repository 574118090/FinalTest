#include "point.h"
point::point() {
	x = 0, y = 0;
}
point::point(double _x, double _y) {
	x = _x, y = _y;
}
bool point::CompareWithX(point a, point b)
{
	return a.x > b.x;
}
bool point::CompareWithY(point a, point b) {
	return a.y > b.y;
}