#pragma once
#include"caculate_output.h"
class vec {
	friend class polygon;
	friend class Caculate;
public:
	vec();
	vec(double _x, double _y);

	void Output();

	vec operator -(vec b);
	vec operator +(vec b);
private:
	double x, y;
};