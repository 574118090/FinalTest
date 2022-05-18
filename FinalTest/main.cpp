#include<iostream>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
#include"polygon.h"
#include"line-segment.h"
#include"line.h"
signed main() {
	point a(0, 0);
	point b(1, 1);
	point c(2, 0);
	
	polygon pl(3);
	pl.AddPoint(a);
	pl.AddPoint(b);
	pl.AddPoint(c);
	pl.OutputPoint();


	//lineSegment a1(0,0,0,1);
	//lineSegment b1(0,0,0,1);
	//a1.judgeRelationship(a1,b1);
	return 0;
}