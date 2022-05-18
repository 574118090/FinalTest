#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"
class lineRay :public line {
public:
	lineRay();

	lineRay(double x1, double y1, double x2, double y2);//点和方向向量

	void Output();

private:
	point startPoint;
	vec v;
};