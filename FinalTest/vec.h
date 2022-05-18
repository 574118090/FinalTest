#pragma once
#include"caculate_output.h"
class vec {
	friend void CaculateOutput(vec a);
public:
	vec();
	vec(int _x, int _y);
	vec operator -(vec b);
	vec operator +(vec b);
private:
	double x, y;
};