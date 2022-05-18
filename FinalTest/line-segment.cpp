#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"
#include"line-segment.h"
#include"math.h"

lineSegment::lineSegment() {
	startPoint = point();
	endPoint = point();
}

lineSegment::lineSegment(double x1, double y1, double x2, double y2) {
	startPoint = point(x1, y1);
	endPoint = point(x2, y2);
}

 void lineSegment::Output() {
	cout << "起点:"; startPoint.Output();
	cout << "终点:"; endPoint.Output();
}

 double lineSegment:: distant(point a, point b) {
	 double distant = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
	 return distant;
 }

 double P(double a, double b, double c) {
	 double p = (a + b + c) / 2;
	 return p;
 }
 
 void lineSegment::judgeRelationship(lineSegment a, lineSegment b) {
	 double slopeA, slopeB;//斜率
	 slopeA = (a.endPoint.y - a.startPoint.y) / (a.endPoint.x - a.startPoint.x);
	 slopeB = (b.endPoint.y - b.startPoint.y) / (b.endPoint.x - b.startPoint.x);

	 double S1,S2,a1,b1,c1,a2,b2,c2,p1,p2;
	 a1 = distant(a.startPoint, b.startPoint);
	 b1 = distant(a.endPoint, b.startPoint);
	 c1 = distant(a.endPoint, a.startPoint);
	 p1 = P(a1, b1, c1);
	 S1 = sqrt(p1 * (p1 - a1) * p1 * (p1 - b1) * p1 * (p1 - c1));

	 a2 = distant(a.startPoint, b.startPoint);
	 b2 = distant(a.endPoint, b.startPoint);
	 c2 = distant(a.endPoint, a.startPoint);
	 p2 = P(a2, b2, c2);
	 S2 = sqrt(p2 * (p2 - a2) * p2 * (p2 - b2) * p2 * (p2- c2));
	 
	 cout << "面积s1为" << S1 << endl;
	 cout << "面积s2为" << S2 << endl;
 }