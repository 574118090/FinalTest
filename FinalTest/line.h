#pragma once
#include"point.h"
#include"vec.h"
class line {
	friend class lineSegment;
	friend class lineRay;
public:
	line();
	line(double x1, double y1, double v1, double v2);//��ͷ�������
	int CompareWithPoint(double x1, double y1, double v1, double v2);

	void Output();
private:
	point p;
	vec v;
};