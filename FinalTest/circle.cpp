#pragma once
#include<iostream>
#include"point.h"
#include"circle.h"
using namespace std;
Circle::Circle() {
	origin=point();
	R = 0;
}
Circle::Circle(double x1, double y1, double r) {
	origin = point(x1,y1);
	R = r;
}

void Circle::Output() {
	cout << "过直线一点：";
	origin.Output();
	cout << "方向向量" << R << endl;
}
	