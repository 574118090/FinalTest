#pragma once
#include"vec.h"
#include"caculate_output.h"
class point {
	friend class Caculate;
	friend class polygon;
	friend class lineSegment;
	friend class circle;
public:
	point();
	point(double _x, double _y);

	void Output();
	void SimpleOutput();
	
	static bool CompareWithX(const point a, const point b);
	static bool CompareWithY(const point a, const point b);
	static double GetPointDistance(const point a, const point b);

	vec operator - (const point b);
	bool operator ==(const point b);
private:
	double x, y;
};