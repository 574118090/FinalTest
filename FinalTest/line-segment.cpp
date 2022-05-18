#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"
#include"line-segment.h"

lineSegment::lineSegment() {
	startPoint = point();
	endPoint = point();
}
lineSegment::lineSegment(double x1, double y1, double x2, double y2) {
	startPoint = point(x1, y1);
	endPoint = point(x2, y2);
}

 