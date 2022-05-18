#include<iostream>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
#include"polygon.h"
signed main() {
	point a(0, 0);
	point b(1, 1);
	point c(2, 0);
	
	polygon pl(3);
	pl.AddPoint(a);
	pl.AddPoint(b);
	pl.AddPoint(c);
	pl.OutputPoint();
	return 0;
}