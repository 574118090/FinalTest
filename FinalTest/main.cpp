#include<iostream>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
#include"polygon.h"
signed main() {
	point a(0, 0);
	point b(1, 1);
	point c(2, 0);
	
	polygon pl(100);
	pl.AddPoint(point(0, 0));
	pl.AddPoint(point(0, 2));
	pl.AddPoint(point(2, 2));
	pl.AddPoint(point(2, 0));
	std::cout << pl.GetC();
	return 0;
}