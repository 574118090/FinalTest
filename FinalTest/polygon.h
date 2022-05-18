#include"point.h"
class polygon {
public:
	polygon();
	polygon(int _size);

	void AddPoint(point a);
	void OutputPoint();
private:
	point* pointCase;
	int size;
	int pointMalloc;
};