#pragma once
#include"caculate_output.h"

double Caculate::Cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;

}
double Caculate::Dot(double x1, double y1, double x2, double y2)
{
	return x1 * y1 + x2 * y2;
}

