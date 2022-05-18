#include<iostream>
#include"point.h"
#include"vec.h"
#include"caculate_output.h"
#include"line-segment.h"
signed main() {
	vec testPoint(1, 2);
	vec testPoint2(3, 4);
	vec tesP = testPoint - testPoint2;
	point outp(1,1);
	cout << Caculate::Cross(1, 1, 1, 1);

	//line a(1,1,2,2);
	//a.Output();

	return 0;
}