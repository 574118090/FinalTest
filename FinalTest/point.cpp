#pragma once
#include<iostream>
#include "point.h"
point::point() {
	x = 0, y = 0;
}
point::point(double _x, double _y) {
	x = _x, y = _y;
}
void point::Output()
{
	std::cout << "(" << x << "," << y << ")\n";
}
void point::SimpleOutput()
{
	std::cout << "(" << x << "," << y << "),";
}
bool point::CompareWithX(const point a,const point b)
{
	return a.x > b.x;
}
bool point::CompareWithY(const point a,const point b) {
	return a.y > b.y;
}

double point::GetPointDistance(const point a, const point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vec point::operator-(const point b)
{
	return vec(x - b.x, y - b.y);
}

bool point::operator==(const point b)
{
	return x==b.x && y==b.y;
}


