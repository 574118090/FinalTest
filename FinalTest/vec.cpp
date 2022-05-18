#include "vec.h"
vec::vec() {

}
vec::vec(int _x, int _y)
{
	x = _x, y = _y;
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