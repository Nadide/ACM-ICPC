#include <cstdio>
#include <iostream>
using namespace std;

struct point {
	int x,y; 
} typedef point;

bool onSegment (point p1, point p2, point q) 
{
	if ( min(p1.x, p2.x) <= q.x  &&  q.x <= max(p1.x, p2.x))
		if (min(p1.y, p2.y) <= q.y  &&  q.y <= max(p1.y, p2.y))
			return true;
	return false;
}

int orien (point p1, point p2, point p3)
// orientation of three points 
{
	int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
	// (p2.y - p1.y) / (p2.x - p1.x) - (p3.y - p2.y) / (p3.x - p2.x)

	if (val == 0 ) return 0;  //collinear
	return (val > 0) ? 1 : 2;  //clock : counterclock
}

bool doIntersect (point p1, point q1, point p2, point q2) 
{
	int o1 = orien (p1,q1,p2);
	int o2 = orien (p1,q1,q2);
	int o3 = orien (p2,q2,p1);
	int o4 = orien (p2,q2,q1);

	//printf ("%d %d %d %d\n", o1,o2,o3,o4);
	if (o1 != o2  && o3 != o4)
		return true;

	if (o1 == 0  &&  onSegment(p1,q1,p2)) return true;
        if (o2 == 0  &&  onSegment(p1,q1,q2)) return true;
        if (o3 == 0  &&  onSegment(p2,q2,p1)) return true;
        if (o4 == 0  &&  onSegment(p2,q2,q1)) return true;	

	return false;
}


int main ()
{
	point p1,q1,p2,q2;

	scanf ("%d %d %d %d", &p1.x, &p1.y, &q1.x, &q1.y);
	scanf ("%d %d %d %d", &p2.x, &p2.y, &q2.x, &q2.y);

	if ( doIntersect(p1,q1,p2,q2) )
		printf ("YES\n");
	else
		printf ("NO\n");

}
