#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"
#include"line-ray.h"

lineRay::lineRay() {
	startPoint = point();
	v = vec();
}

lineRay::lineRay(double x1, double y1, double x2, double y2) {
	startPoint = point(x1,y1);
	v = vec(x2,y2);
}

void lineRay::Output() {
	cout << "起始点"; startPoint.Output();
	cout << "方向向量"; v.Output();
}
