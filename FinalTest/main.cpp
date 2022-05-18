#include<iostream>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
signed main() {
	vec testPoint(1, 2);
	vec testPoint2(3, 4);
	vec tesP = testPoint - testPoint2;
	point outp(1,1);
	tesP.Output();
	return 0;
}