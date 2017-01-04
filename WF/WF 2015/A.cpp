#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double p,a,b,c,d;

inline double calc (double k) {
	return p*(sin (a*k+b)+cos (c*k+d)+2);
}

int main () {
	scanf ("%lf %lf %lf %lf %lf %d", &p, &a, &b, &c, &d, &n);

	double ans = 0,mak = calc (1);
	for (int i = 2;i <= n;i ++) {
		double curr = calc (i);
		ans = max (ans, mak-curr);
		mak = max (mak, curr);
	}
	printf ("%lf\n", ans);
}