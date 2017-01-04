#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define pii pair<double, double>

double r;
pii a,b;

inline double Dist (pii a) {
	return sqrt (a.first*a.first+a.second*a.second);
}

inline double Dist (pii a, pii b) {
	return Dist (pii (a.first-b.first, a.second-b.second));
}

inline double Dist2 (pii a) {
	return a.first*a.first+a.second*a.second;
}

inline double Dist2 (pii a, pii b) {
	return Dist (pii (a.first-b.first, a.second-b.second));
}

inline double Dot (pii a, pii b) {
	return a.first*b.first+a.second*b.second;
}

inline double PointToLine (pii c, pii a, pii b) {
	double r = Dist2 (pii (a.first-b.first, a.second-b.second));
	pii cma = pii (c.first-a.first, c.second-a.second);
	pii bma = pii (b.first-a.first, b.second-a.second);
	r = Dot (cma, bma)/r;
	pii q;
	if (r < 0) {
		q = a;
	} else if (r > 1) {
		q = b;
	} else {
		q = pii (a.first+bma.first*r, a.second+bma.second*r);
	}
	return Dist (c, q);
}

inline double findAngle (double a, double b, double c) {
	return acos ((a*a+b*b-c*c)/(2*a*b));
}

inline double findAngle (pii a, pii b, pii c) {
	double ab = Dist (a, b),ac = Dist (a, c),bc = Dist (b, c);
	return findAngle (ab, ac, bc);
}

inline double calc (pii a, double r, pii b) {
	return sqrt (Dist2 (a, b)-r*r);
}

inline double solve () {
	pii o = pii (0, 0);
	
	if (PointToLine (o, a, b) < r) {
		double ans1 = calc (o, r, a);
		double ans2 = calc (o, r, b);
		double angle1 = findAngle (Dist (o, a), r, ans1);
		double angle2 = findAngle (Dist (o, b), r, ans2);
		double angle = findAngle (o, a, b);
		angle -= (angle1+angle2);
		double ans3 = r*angle;
		return ans1+ans2+ans3;
	} else {
		return Dist (a, b);
	}
}

int main () {
	int test;
	scanf ("%d", &test);

	while (test --) {
		scanf ("%lf %lf %lf %lf %lf", &a.first, &a.second, &b.first, &b.second, &r);

		printf ("%.3lf\n", solve ());
	}
}