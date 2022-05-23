#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"

class lineSegment :public line {	
public:
	lineSegment();
	lineSegment(double x1,double y1,double x2,double y2);//�����յ�
	virtual void Output();
	double distant(point a, point b);
	int ifCoincide(lineSegment b);//�Ƿ��غ�
	int ifIntersect(lineSegment b);//�Ƿ��ཻ
private:
	point startPoint;
	point endPoint;
};