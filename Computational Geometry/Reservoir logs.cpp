#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e4+10;

#define pii pair<double, double>

int n;
pii p[N];
double w,a,b,c;

inline double Area (pii p[], int n) {
	double A = 0;
	p[n] = p[0];
	for (int i = 0;i < n;i ++) {
		A += p[i].first*p[i+1].second-p[i].second*p[i+1].first;
	}
	return fabs (0.5*A);
}

int main () {
	int test;
	scanf ("%d", &test);

	while (test --) {
		scanf ("%d", &n);
		for (int i = 0;i < n;i ++) {
			scanf ("%lf %lf", &p[i].first, &p[i].second);
		}
		scanf ("%lf", &w);
		scanf ("%lf %lf %lf", &a, &b, &c);

		double maxV = Area (p, n)*w,v = maxV*a/100.0;

		v -= b;
		if (v < 0) {
			v = 0;
			printf ("Lack of water. ");
		}
		v += c;
		if (v > maxV) {
			v = maxV;
			printf ("Excess of water. ");
		}
		printf ("Final percentage: %d%%\n", (int)(v*100.0/maxV));
	}
}