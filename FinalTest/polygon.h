#include"point.h"
#include"vec.h"
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
	int GetSize();

	static bool OnPolygon(point a, polygon b);
	static int PointPosition(point a, polygon b);
private:
	edge* pointFst;
	edge* pointCase;
	int size;
	int pointMalloc;
};