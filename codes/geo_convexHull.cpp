// Convex Hull | Jarvis's Algorithm or Wrapping
#include<cstdio>
#include <vector>
using namespace std;

struct Point {
	int x,y;
} typedef Point;

int orient (Point p1, Point p2, Point p3)
{
	int val = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x);

	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1 : 2;  // clock : counterclock wise	
}

void convexHull (Point points[], int n)
{
	int l=0,p,q;

	if (n < 3) return;

	vector<Point> hull;

	for (int i=0; i<n; i++)
		if (points[i].x < points[l].x)
			l = i;

	p = l;
	do {
		hull.push_back(points[p]);
		q = (p+1)%n;
		for (int i=0; i<n; i++)
			if (orient(points[p], points[i], points[q]) == 2)
				q = i;
		p = q;

	} while (p != l);


	for (int i=0; i<hull.size(); i++)
		printf ("(%d,%d)\n", hull[i].x,hull[i].y);	
}

int main ()
{
	int n;
	Point points[101];

	scanf ("%d", &n);
	for (int i=0; i<n; i++) 
		scanf ("%d %d", &points[i].x, &points[i].y);

	convexHull (points, n);

	return 0;
}
