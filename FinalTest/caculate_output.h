#pragma once
#include<iostream>
#include<stdio.h>
#include"polygon.h"
using namespace std;
class Caculate {
public:
	static double Cross(double x1, double y1, double x2, double y2);
	static double Dot(double x1, double y1, double x2, double y2);
	//static double GetS(polygon a);
};