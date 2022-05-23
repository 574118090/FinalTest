#pragma once
#include<iostream>
#include "vec.h"
vec::vec() {
	x = 0, y = 0;
}
vec::vec(double _x, double _y)
{
	x = _x, y = _y;
}
void vec::Output()
{
	std::cout << "(" << x << "," << y << ")\n";
}

void vec::SimpleOutput() {
	std::cout << "(" << x << "," << y << ")";
}

vec vec::operator-(const vec b)
{
	vec res(x,y);
	res.x -= b.x;
	res.y -= b.y;
	return res;
}
vec vec::operator+(const vec b)
{
	vec res(x, y);
	res.x += b.x;
	res.y += b.y;
	return res;
}