//http://topic.csdn.net/t/20011022/09/333494.html
// Judge wether a point is in a triangle or not
// the absolute value of the cross product of two vectors 
// is two times of the area of the triangle
// S = |a||b|sinx/2 = axb/2
//http://apps.hi.baidu.com/share/detail/19939871
//http://www.ics.uci.edu/~eppstein/161/960307.html //good one!

//Solution:
//If a point is within a triangle, the sum of the area of the three small triangles it forms with the three points of 
//this triangle equal to the area of this triangle.
//How to calculate the area of a triangle given three points? Remember the formula here : S = |A||B|sin@ = AXB/2
//AXB stands for cross product


#include <math.h>
struct INT_POINT 
{
	int x;
	int y;
	INT_POINT(int n1 = 0, int n2 = 0) : x(n1), y(n2) {}
};

int CrossProduct(INT_POINT p1, INT_POINT p2, INT_POINT p3)
{
	int ret = ((p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x));
	return ret<0 ? 0-ret : ret;
}

bool InTriangle(INT_POINT p1, INT_POINT p2, INT_POINT p3, INT_POINT pt)
{
	int S1 = CrossProduct(p1, p2, p3);
	int S2 = CrossProduct(p1, p2, pt)+CrossProduct(p1, p3, pt)+CrossProduct(p3, p2, pt);

	return S1==S2;
}

void test()
{
	cout<<InTriangle(INT_POINT(0,0), INT_POINT(0,2), INT_POINT(4,0), INT_POINT(1,5))<<endl;
}