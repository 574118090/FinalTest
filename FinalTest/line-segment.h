#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"

class lineSegment :public line {	
public:
	lineSegment();
	lineSegment(double x1,double y1,double x2,double y2);//起点和终点
	virtual void Output();
	double distant(point a, point b);
	int ifCoincide(lineSegment b);//是否重合
	int ifIntersect(lineSegment b);//是否相交
private:
	point startPoint;
	point endPoint;
};