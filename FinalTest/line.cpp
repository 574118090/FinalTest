#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"
using namespace std;

line::line() {
	point();
	vec();
}

line::line(double x1, double y1, double v1, double v2) {
	point(x1, y1);
	vec(v1, v2);
}

bool line::CompareWithPoint(double x1, double y1, double v1, double v2) {
	if (Caculate::Cross(x1, y1, v1, v2) > 0)
		return 1;//在直线上方
	else if (Caculate::Cross(x1, y1, v1, v2) == 0)
		return 2;//在直线上
	else if (Caculate::Cross(x1, y1, v1, v2) < 0)
		return 3;//在直线下方
}
