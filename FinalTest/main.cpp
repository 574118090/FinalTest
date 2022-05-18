#include<iostream>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
signed main() {
	vec testPoint(1, 2);
	vec testPoint2(3, 4);
	vec outp = testPoint-testPoint2;
	CaculateOutput(outp);
	return 0;
}