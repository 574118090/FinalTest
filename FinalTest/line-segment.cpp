#pragma once
#include<iostream>
#include"line.h"
#include"point.h"
#include"vec.h"
#include"line-segment.h"
#include<cmath>
#include<math.h>
#include"caculate_output.h"
using namespace std;

lineSegment::lineSegment() {
	startPoint = point();
	endPoint = point();
}

lineSegment::lineSegment(double x1, double y1, double x2, double y2) {
	startPoint = point(x1, y1);
	endPoint = point(x2, y2);
}

lineSegment::lineSegment(point a, point b) {
	startPoint = a;
	endPoint = b;
}

 void lineSegment::Output() {
	 cout << "From: ";
	 startPoint.SimpleOutput();
	 cout << " to: ";
	 endPoint.Output();
}

 double lineSegment:: distant(point a, point b) {
	 double distant = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
	 return distant;
 }

 double P(double a, double b, double c) {
	 double p = (a + b + c) / 2;
	 return p;
 }


 
 int lineSegment::ifCoincide(lineSegment b) {//判断是否重合
	 double slopeA, slopeB;//斜率
	 lineSegment a; a=*this;
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
	 
	 if (S1 == 0 && S2 == 0) return 1;
	 else return 0;
	// cout << "面积s1为" << S1 << endl;
	 //cout << "面积s2为" << S2 << endl;
 }

 int lineSegment::ifIntersect(lineSegment b) {
	 lineSegment a; a = *this;
	 int i = 0;
	 vec v1, v2;
	 v1 = a.startPoint.operator-(a.endPoint);
	 v2 = b.startPoint.operator-(b.endPoint);
	 if (min(a.startPoint.x, a.endPoint.x) <= max(b.startPoint.x, b.endPoint.x) &&
		 min(b.startPoint.x, b.endPoint.x) <= max(a.startPoint.x, a.endPoint.x) &&
		 min(a.startPoint.y, a.endPoint.y) <= max(b.startPoint.y, b.endPoint.y) &&
		 min(b.startPoint.y, b.endPoint.y) <= max(a.startPoint.y, a.endPoint.y)) i = 1;
	 else i = 0;
	 //cout << "i====" << i << endl;
	 if (Caculate::Cross(b.startPoint.x, b.startPoint.y, v1.x, v1.y) >= 0 &&
		 Caculate::Cross(b.endPoint.x, b.endPoint.y, v1.x, v1.y) <= 0 ||
		 Caculate::Cross(b.startPoint.x, b.startPoint.y, v1.x, v1.y) <= 0 &&
		 Caculate::Cross(b.endPoint.x, b.endPoint.y, v1.x, v1.y) >= 0)  i += 1;
	 else i = 0;
	 //cout << "i====" << i << endl;
	 return i;//i为2则有交点
 }

