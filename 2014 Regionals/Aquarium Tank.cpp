#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
double D;
struct point {
	double x,y;

	point (double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
	}
} p[N],L[N],R[N];
int nl,nr;

inline double Area (point a, point b, point c, point d) {
	double hi = a.x*b.y+b.x*c.y+c.x*d.y+d.x*a.y;
	double lo = a.y*b.x+b.y*c.x+c.y*d.x+d.y*a.x;
	return 0.5*abs (hi-lo);
}

inline point FindIntersect (point a, point b, double y) {
	double x = (y-a.y)/(b.y-a.y)*(b.x-a.x)+a.x;
	return point (x, y);
}

inline bool check (double k) {
	double vol = 0;

	int l = 0,r = 0;
	point l1 = L[l],r1 = R[r];
	while (l1.y < k) {
		point l2,r2;
		if (L[l+1].y < R[r+1].y) {
			l2 = L[++ l];
			r2 = FindIntersect (R[r], R[r+1], l2.y);
		} else if (L[l+1].y > R[r+1].y) {
			r2 = R[++ r];
			l2 = FindIntersect (L[l], L[l+1], r2.y);
		} else {
			l2 = L[++ l];
			r2 = R[++ r];
		}
		if (k < l2.y) {
			l2 = FindIntersect (l1, l2, k);
			r2 = FindIntersect (r1, r2, k);
		}

		vol += Area (l1, l2, r2, r1);

		l1 = l2;
		r1 = r2;
	}

	return vol >= D;
}

int main () {
	while (scanf ("%d", &n) == 1) {
		double d,l,hi = 0.0;
		scanf ("%lf %lf", &d, &l);
		D = l*1000.0/d;

		int minP = 0;
		for (int i = 0;i < n;i ++) {
			scanf ("%lf %lf", &p[i].x, &p[i].y);
			if (p[i].y < p[minP].y) {
				minP = i;
			}
			hi = max (hi, p[i].y);
		}
		nl = nr = 0;

		for (;p[minP].y == p[(minP+1)%n].y;minP = (minP+1)%n) ;
		int curr;
		for (curr = minP;p[(curr+1)%n].y > p[curr].y;curr = (curr+1)%n) {
			R[nr ++] = p[curr];
		}
		R[nr ++] = p[curr];

		for (;p[minP].y == p[(minP+n-1)%n].y;minP = (minP+n-1)%n) ;
		for (curr = minP;p[(curr+n-1)%n].y > p[curr].y;curr = (curr+n-1)%n) {
			L[nl ++] = p[curr];
		}
		L[nl ++] = p[curr];

		double lo = 0.0;
		while (hi-lo > 1e-6) {
			double md = (lo+hi)/2.0;
			if (check (md)) {
				hi = md;
			} else {
				lo = md+1e-6;
			}
		}
		printf ("%.2lf\n", lo);
	}
}