#pragma once
class point {
	friend void CaculateOutput(point a);
public:
	point();
	point(double _x, double _y);
	static bool CompareWithX(point a, point b);
	static bool CompareWithY(point a, point b);
private:
	double x, y;
};