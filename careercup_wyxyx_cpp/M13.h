//Given two rectangles, find if there is an overlap between them ? 
//rect1 is depicted as a set of two diagonally opposite points in a rectangle.
//bool isOverlap(rect1, rect2);

// Get the center of the two rectangle says c1,c2
// Judge wether two rectangles sre overlapped with each other by the distance of their X coordinate and Y coordinate

struct RCT
{
	float fLTX;
	float fLTY;
	float fRBX;
	float fRBY;

	RCT(float f1, float f2, float f3, float f4)
		: fLTX(f1),fLTY(f2),fRBX(f3),fRBY(f4) {}
	void CalcCenter(float& cx, float& cy)
	{
		cx = fLTX + (fRBX-fLTX)/2;
		cy = fRBY + (fLTY-fRBY)/2;
	}
};

bool isOverlap(RCT rect1, RCT rect2)
{
	float c1x, c1y, c2x, c2y;
	rect1.CalcCenter(c1x, c1y);
	rect2.CalcCenter(c2x, c2y);

	return fabs(c1x-c2x)<(fabs((rect1.fRBX-rect1.fLTX)/2)+fabs((rect2.fRBX-rect2.fLTX)/2))
		&& fabs(c1y-c2y)<(fabs((rect1.fRBY-rect1.fLTY)/2)+fabs((rect2.fRBY-rect2.fLTY)/2));
}

void test()
{
	RCT rt1(0.0,2.12,2.2,0.0);
	RCT rt2(100.1,300.0,300.1,100.0);
	cout<<isOverlap(rt1, rt2)<<endl;
}