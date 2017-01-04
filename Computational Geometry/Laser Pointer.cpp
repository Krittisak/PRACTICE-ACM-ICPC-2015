#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos (-1);

double l,w,a;

int main () {
	int test;
	scanf ("%d", &test);

	while (test --) {
		scanf ("%lf %lf %lf", &l, &w, &a);

		a = a*PI/180.0;

		if (a == 0) {
			printf ("1.000\n");
		} else {
			double A,B;
			double l1 = w/tan (a),len = w/sin (a);
			int rd = l/l1;
			A = rd*len;

			double l2 = l-rd*l1;
			A += l2/cos (a);
			double w1 = l2*tan (a);
			if (rd&1) {
				w1 = w-w1;
			}
			B = sqrt (l*l+w1*w1);

			printf ("%.3lf\n", A/B);
		}
	}
}