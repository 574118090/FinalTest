#pragma once
#include"point.h"
#include"vec.h"
class line {
public:
	line();
	line(double x1, double y1, double v1, double v2);
	bool CompareWithPoint(double x1, double y1, double v1, double v2);
private:
	point p;
	vec v;
};