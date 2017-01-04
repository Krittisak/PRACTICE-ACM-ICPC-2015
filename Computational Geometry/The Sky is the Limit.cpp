#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
struct moun {
	double x,h,b;
} p[N];
struct event {
	double x,y,m,e;
	event (double _x = 0, double _y = 0, double _m = 0, double _e = 0) {
		x = _x;
		y = _y;
		m = _m;
		e = _e;
	}
} events[N*N*4];

inline bool comp (event a, event b) {
	if (a.x == b.x) {
		return a.m < b.m;
	} else {
		return a.x < b.x;
	}
}

inline event intersect (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double m1 = (y2-y1)/(x2-x1),m2 = (y4-y3)/(x4-x3);
	if (m1 == m2) {
		return event (-1, -1, -1, -1);
	}
	double x = (m1*x1-m2*x3+y3-y1)/(m1-m2);
	double y = m1*(x-x1)+y1;
	if (x1 <= x and x <= x2 and x3 <= x and x <= x4) {
		if (m1 > m2) {
			return event (x, y, m1, x2);
		} else {
			return event (x, y, m2, x4);
		}
	} else {
		return event (-1, -1, -1, -1);
	}
}

inline double Dist (double x1, double y1, double x2, double y2) {
	return sqrt ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline double solve () {
	m = 0;
	for (int i = 0;i < n;i ++) {
		events[m ++] = event (p[i].x-p[i].b/2, 0, 2*p[i].h/p[i].b, p[i].x);
		events[m ++] = event (p[i].x, p[i].h, -2*p[i].h/p[i].b, p[i].x+p[i].b/2);
		events[m ++] = event (p[i].x+p[i].b/2, 0, 0, -1);
	}

	for (int i = 0;i < n;i ++) {
		for (int j = i+1;j < n;j ++) {
			event a = intersect (p[i].x-p[i].b/2, 0, p[i].x, p[i].h, p[j].x-p[j].b/2, 0, p[j].x, p[j].h);
			if (a.y != -1) {
				events[m ++] = a;
			}
			a = intersect (p[i].x-p[i].b/2, 0, p[i].x, p[i].h, p[j].x, p[j].h, p[j].x+p[j].b/2, 0);
			if (a.y != -1) {
				events[m ++] = a;
			}
			a = intersect (p[i].x, p[i].h, p[i].x+p[i].b/2, 0, p[j].x-p[j].b/2, 0, p[j].x, p[j].h);
			if (a.y != -1) {
				events[m ++] = a;
			}
			a = intersect (p[i].x, p[i].h, p[i].x+p[i].b/2, 0, p[j].x, p[j].h, p[j].x+p[j].b/2, 0);
			if (a.y != -1) {
				events[m ++] = a;
			}
		}
	}

	sort (events, events+m, comp);

	double ans = 0;
	event l = event (0, 0, 0, -1);
	for (int i = 0;i < m;i ++) {
		event e = events[i];
		//printf ("%lf %lf %lf %lf\n", e.x, e.y, e.m, e.e);
		if (l.e == -1) {
			l = e;
		} else if (l.e == e.x) {
			ans += Dist (l.x, l.y, e.x, l.m*(e.x-l.x)+l.y);
			l = e;
		} else {
			double x = l.x,y = l.y;
			l.y = l.m*(e.x-l.x)+l.y;
			l.x = e.x;

			ans += Dist (x, y, l.x, l.y);

			if (l.y <= e.y) {
				l = e;
			}
		}
	}

	return ans;
}

int main () {
	int Case = 0;
	while (scanf ("%d", &n) == 1 and n != 0) {
		for (int i = 0;i < n;i ++) {
			scanf ("%lf %lf %lf", &p[i].x, &p[i].h, &p[i].b);
		}

		printf ("Case %d: %.lf\n\n", ++ Case, solve ());
	}
}