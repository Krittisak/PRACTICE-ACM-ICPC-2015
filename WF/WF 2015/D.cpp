#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e4+10;
const double PI = acos (-1);

int n,s;
struct sphere {
	double r,x,y,z;
} p[N];

inline double fullVolume (double r) {
	return 4.0/3.0*PI*r*r*r;
}

inline double partialVolume (double r, double k) {
	return PI*(r*r*k-k*k*k/3.0+2.0/3.0*r*r*r);
}

inline double check (double h) {
	double sum = 100*100*h;

	for (int i = 0;i < n;i ++) {
		if (p[i].z+p[i].r <= h) {
			sum -= fullVolume (p[i].r);
		} else if (p[i].z-p[i].r < h) {
			sum -= partialVolume (p[i].r, h-p[i].z);
		}
	}

	return sum;
}

int main () {
	scanf ("%d %d", &n, &s);

	double total = 100*100*100;
	for (int i = 0;i < n;i ++) {
		scanf ("%lf %lf %lf %lf", &p[i].r, &p[i].x, &p[i].y, &p[i].z);
		p[i].r /= 1e3;
		p[i].x /= 1e3;
		p[i].y /= 1e3;
		p[i].z /= 1e3;
		total -= fullVolume (p[i].r);
	}

	double last = 0;
	for (int i = 1;i <= s;i ++) {
		double lo = 0,hi = 100.0;
		while (hi-lo > 1e-9) {
			double md = (lo+hi)/2.0;
			if (check (md)-i*total/s > 1e-9) {
				hi = md-1e-9;
			} else {
				lo = md;
			}
		}
		printf ("%lf\n", lo-last);
		last = lo;
	}
}