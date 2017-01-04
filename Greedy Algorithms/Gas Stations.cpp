#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e4+10;

#define pii pair<int, int>

int n,l;
pii x[N];

inline bool comp (pii a, pii b) {
	return a.first < b.first;
}

int main () {
	while (scanf ("%d %d", &l ,&n) == 2 and not (l == 0 and n == 0)) {
		for (int i = 0;i < n;i ++) {
			int a,b;
			scanf ("%d %d", &a, &b);
			x[i] = pii (a-b, a+b);
		}

		sort (x, x+n, comp);

		int f = 0,i = 0,c = 0;
		while (f < l) {
			int r = f;
			for (;i < n and x[i].first <= f;i ++) {
				r = max (r, x[i].second);
			}
			if (f == r) {
				break;
			}
			c ++;
			f = r;
		}
		if (f < l) {
			c = -1;
		} else {
			c = n-c;
		}
		printf ("%d\n", c);
	}
}