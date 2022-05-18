#pragma once
#include<iostream>
#include"caculate_output.h"
#include"line.h"
#include"point.h"
#include"vec.h"
using namespace std;

line::line() {
	p=point();
	v=vec();
}

line::line(double x1, double y1, double v1, double v2) {
	p=point(x1, y1);
	v=vec(v1, v2);
}

int line::CompareWithPoint(double x1, double y1, double v1, double v2) {
	double res = Caculate::Cross(x1, y1, v1, v2);
	if (res > 0)return 1;//��ֱ���Ϸ�
	else if (res == 0)return 2;//��ֱ����
	else return 3;//��ֱ���·�
}
