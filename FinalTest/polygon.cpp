#include"polygon.h"

polygon::polygon()
{
	size = 3;
	pointCase = new point[1000];
	pointMalloc = 0;
}

polygon::polygon(int _size) {
	size = _size;
	pointCase = new point[_size + 1];
	pointMalloc = 0;
}

void polygon::AddPoint(point a) {
	*(pointCase+pointMalloc) = a;
	(pointCase + pointMalloc)->Output();
	pointMalloc++;
}

void polygon::OutputPoint() {
	for (register int i = 0; i < pointMalloc; i++) {
		point temp;
		temp = *(pointCase + pointMalloc);
		temp.Output();
	}
}