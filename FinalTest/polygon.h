#include"point.h"
struct edge {
	edge* head;
	point p;
	edge* next;
};

class polygon {
public:
	polygon();
	polygon(int _size);

	double GetS();
	double GetC();
	void AddPoint(point a);
	void DeletePoint(point a);
	void ChangePoint(point a, point b);
	void OutputPoint();

private:
	edge* pointFst;
	edge* pointCase;
	int size;
	int pointMalloc;
};