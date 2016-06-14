// Check if a given point lies inside or outside a polygon
// Doesnt work properly?
#include <cstdio>
#define INF 0X7FFFFFFF
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
int inf[2] = {INF,-INF}, x;

struct point {
	int x, y;
} typedef point;

bool onSegment (point p1, point p2, point q)
{
	if (min(p1.x,p2.x) <= q.x  && q.x <= max(p1.x,p2.x))
		if (min(p1.y,p2.y) <= q.y  &&  q.y <= max(p1.y,p2.y))
			return true;
	return false;
}

int orient (point p1, point p2, point p3) 
// orientation of three point
{
	int val = (p2.y-p1.y)*(p3.x-p2.x) - (p3.y-p2.y)*(p2.x-p1.x); 
		
	if (val == 0) return 0;      //collinear
	return (val > 0) ? 1 : 2 ;   //clock : counterclock
}

bool doIntersect (point p1, point q1, point p2, point q2) 
{
	int o1 = orient (p1,q1,p2);
	int o2 = orient (p1,q1,q2);
	int o3 = orient (p2,q2,p1);
	int o4 = orient (p2,q2,q1);

	if (o1 != o2  && o3 != o4)
		return true;

	// if its collinear check whether on segment
	if (o1 == 0  &&  onSegment(p1,q1,p2)) return true;
        if (o2 == 0  &&  onSegment(p1,q1,q2)) return true;
        if (o3 == 0  &&  onSegment(p2,q2,p1)) return true;
        if (o4 == 0  &&  onSegment(p2,q2,q1)) return true;

	return false;
}

bool isInside (point polygon[], int n, point p)
{
	if (n < 3) return false;

	point extreme = {inf[x], p.y};
	int count=0, i=0;
	do {
		int next = (i+1)%n; 
		
		if ( doIntersect(polygon[i], polygon[next], p, extreme) ) 
		{
			// *** code 1 ***
			if ( orient(polygon[i], polygon[next], p) == 0 )
				if ( onSegment(polygon[i], polygon[next], p))
					return true;
				else {
					x++; // change the infinitive direction
					return isInside(polygon, n, p);
				}

			// *** code 2 ***
			// if ( orient(polygon[i], polygon[next], p) == 0 )
                        //        return onSegment(polygon[i], polygon[next], p);

			count++;	
		}
		i = next;
	
	} while (i != 0); 

	return (count % 2) == 1 ;
}

int main () 
{
	point polygon[100], p;
	int n;

	scanf ("%d", &n);
	for (int i=0; i<n; i++)
		scanf ("%d %d", &polygon[i].x, &polygon[i].y);
	scanf ("%d %d", &p.x, &p.y);	

	if ( isInside(polygon, n, p) )
		printf ("YES\n");
	else
		printf ("NO\n");	
	
}
