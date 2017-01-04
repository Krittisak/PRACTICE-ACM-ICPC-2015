#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;

const int N = 110;
const double PI = acos (-1),EPS = 1e-9;

int n;
double r;
pdd p[N];

inline double hypot (pdd a) {

	return a.first*a.first+a.second*a.second;

}

inline double dist (pdd a) {

	return sqrt (hypot (a));

}

inline double angle (pdd a, pdd b, pdd c) {

	pdd ab = pdd (b.first-a.first, b.second-a.second);
	pdd ac = pdd (c.first-a.first, c.second-a.second);

	return acos ((ab.first*ac.first+ab.second*ac.second)/(dist (ab)*dist (ac)));

}

inline double cross (pdd a, pdd b, pdd c) {

	pdd ab = pdd (b.first-a.first, b.second-a.second);
	pdd ac = pdd (c.first-a.first, c.second-a.second);

	return (ab.first*ac.second-ab.second*ac.first)/2.0;

}

inline int dir (pdd a, pdd b, pdd c) {

	if (cross (a, b, c) > EPS) {

		return 1;

	} else {

		return -1;

	}

}

inline double sector (pdd o, pdd a, pdd b) {

	return angle (o, a, b)/2.0*r*r*dir (o, a, b);

}

inline pdd findPoint (pdd a, pdd b, double k) {

	pdd ab = pdd (b.first-a.first, b.second-a.second);
	return pdd (a.first+ab.first*k, a.second+ab.second*k);

}

inline pdd intersect (pdd a, pdd b, double d) {

	double lo = 0,hi = 1;
	while (hi-lo > EPS) {

		double md = (lo+hi+EPS)/2.0;
		if (hypot (findPoint (a, b, md)) > d*d+EPS) {

			hi = md-EPS;

		} else {

			lo = md;

		}

	}
	return findPoint (a, b, lo);

}

inline pdd midPoint (pdd a, pdd b) {

	return findPoint (a, b, 0.5);

}

int main () {

	scanf ("%d %lf", &n, &r);
	for (int i = 0;i < n;i ++) {

		scanf ("%lf %lf", &p[i].first, &p[i].second);
	
	}
	p[n] = p[0];

	double area = 0;
	pdd o (0, 0);
	for (int i = 0;i < n;i ++) {

		if (hypot (p[i]) < r*r+EPS) {

			if (hypot (p[i+1]) < r*r+EPS) {

				area += cross (o, p[i], p[i+1]);

			} else {

				pdd a = intersect (p[i], p[i+1], r);
				area += cross (o, p[i], a)+sector (o, a, p[i+1]);

			}

		} else {

			if (hypot (p[i+1]) < r*r+EPS) {

				pdd a = intersect (p[i+1], p[i], r);
				area += sector (o, p[i], a)+cross (o, a, p[i+1]);

			} else {
				
				pdd a = p[i],c = p[i+1];
				pdd b = midPoint (a, c);
				if (hypot (a) > hypot (c)) {

					a = intersect (b, a, dist (c));

				} else {

					c = intersect (b, c, dist (a));

				}
				b = midPoint (a, c);

				if (hypot (b) < r*r-EPS) {

					a = intersect (b, p[i], r);
					c = intersect (b, p[i+1], r);
					area += sector (o, p[i], a)+cross (o, a, c)+sector (o, c, p[i+1]);

				} else {

					area += sector (o, p[i], p[i+1]);

				}

			}

		}

	}
	area = fabs (area);
	printf ("%lf\n", area);

}