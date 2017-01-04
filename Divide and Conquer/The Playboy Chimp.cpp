#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5e4+10;

int n,x[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0;i < n;i ++) {
		scanf ("%d", &x[i]);
	}

	int q;
	scanf ("%d", &q);

	while (q --) {
		int c;
		scanf ("%d", &c);

		int a = lower_bound (x, x+n, c)-x-1;
		int b = upper_bound (x, x+n, c)-x;

		if (a < 0) {
			printf ("X ");
		} else {
			printf ("%d ", x[a]);
		}

		if (b >= n) {
			printf ("X\n");
		} else {
			printf ("%d\n", x[b]);
		}
	}
}