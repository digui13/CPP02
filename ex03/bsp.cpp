#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed ax, ay, bx, by, cx, cy, px, py;
	bool check1, check2, check3;

	ax = a.GetPointX();
	ay = a.GetPointY();
	bx = b.GetPointX();
	by = b.GetPointY();
	cx = c.GetPointX();
	cy = c.GetPointY();
	px = point.GetPointX();
	py = point.GetPointY();
	
	check1 = (px - bx) * (ay - by) - (ax - bx) * (py - by) < 0.0f;
	check2 = (px - cx) * (by - cy) - (bx - cx) * (py - cy) < 0.0f;
	check3 = (px - ax) * (cy - ay) - (cx - ax) * (py - ay) < 0.0f;

	return ((check1 == check2) && (check1 == check3));
}