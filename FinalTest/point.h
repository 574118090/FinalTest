#pragma once
#include"vec.h"
class point {
public:
	point();
	point(double _x, double _y);


	void Output();
	

	static bool CompareWithX(const point a, const point b);
	static bool CompareWithY(const point a, const point b);
	static double GetPointDistance(const point a, const point b);

	vec operator - (const point b);
private:
	double x, y;
};