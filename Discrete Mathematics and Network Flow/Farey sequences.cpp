#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

#define pii pair<int, int>

pii f[N*N];
int n,k,c;

inline int gcd (int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd (b, a%b);
	}
}

inline bool comp (pii a, pii b) {
	return a.first*b.second < a.second*b.first;
}

int main () {
	c = 0;
	for (int i = 1;i < N;i ++) {
		for (int j = 1;j <= i;j ++) {
			int g = gcd (i, j);
			f[c ++] = pii (j/g, i/g);
		}
	}
	sort (f, f+c, comp);
	c = unique (f, f+c)-f;

	while (scanf ("%d %d", &n, &k) == 2) {
		for (int i = 0,j = 0;i < c;i ++) {
			if (f[i].second <= n) {
				if (++ j == k) {
					printf ("%d/%d\n", f[i].first, f[i].second);
					break;
				}
			}
		}
	}
}