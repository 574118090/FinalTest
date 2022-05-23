#pragma once
#include"caculate_output.h"
class vec {
	friend class polygon;
public:
	vec();
	vec(double _x, double _y);

	void Output();

	vec operator -(vec b);
	vec operator +(vec b);
private:
	double x, y;
};