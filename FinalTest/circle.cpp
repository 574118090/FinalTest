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
	cout << "��ֱ��һ�㣺";
	origin.Output();
	cout << "��������" << R << endl;
}
	