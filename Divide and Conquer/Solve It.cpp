#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double p,q,r,s,t,u;

inline double calc (double x) {
	return p*exp (-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main () {
	while (scanf ("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6) {
		if (calc (0)*calc (1) > 0) {
			printf ("No solution\n");
			continue;
		}

		double lo = 0,hi = 1;
		while (hi-lo > 1e-9) {
			double md = (lo+hi)/2;

			if (calc (md) > 1e-9) {
				lo = md+1e-9;
			} else {
				hi = md;
			}
		}
		printf ("%.4lf\n", lo);
	}
}