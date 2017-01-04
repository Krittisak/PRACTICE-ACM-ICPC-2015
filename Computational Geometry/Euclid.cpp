#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double xa,ya,xb,yb,xc,yc,xd,yd,xe,ye,xf,yf;

inline double cross (double x1, double y1, double x2, double y2) {
	return x1*y2-x2*y1;
}

int main () {
	while (scanf ("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd, &xe, &ye, &xf, &yf) == 12) {
		if (xa == 0 and ya == 0 and xb == 0 and yb == 0 and xc == 0 and yc == 0 and xd == 0 and yd == 0 and xe == 0 and ye == 0 and xf == 0 and yf == 0) {
			break;
		}

		double k = fabs (0.5*cross (xe-xd, ye-yd, xf-xd, yf-yd)/cross (xc-xa, yc-ya, xb-xa, yb-ya));

		double xh = k*(xc-xa)+xa;
		double yh = k*(yc-ya)+ya;
		double xg = xh+xb-xa;
		double yg = yh+yb-ya;

		printf ("%.3lf %.3lf %.3lf %.3lf\n", xg, yg, xh, yh);
	}
}