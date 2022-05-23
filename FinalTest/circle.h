#pragma once
#include"point.h"
#include"vec.h"
class Circle {
public:
	Circle();
	Circle(double x1,double y1,double r);//点和方向向量
	void Output();
private:
	point origin;
	double R;
};