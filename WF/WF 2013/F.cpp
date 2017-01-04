#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6+10,inf = 1e9;

int n,k;
int m,a[N];

inline bool check (int md) {
	int cnt = 0;
	for (int i = 0;i <= cnt*2*k and i+1 < m;i ++) {
		if (a[i+1]-a[i] <= md) {
			cnt ++;
			i ++;
		}
	}

	return cnt >= n;
}

int main () {
	scanf ("%d %d", &n, &k);

	m = 2*n*k;
	for (int i = 0;i < m;i ++) {
		scanf ("%d", &a[i]);
	}

	sort (a, a+m);

	int lo = 0,hi = inf;
	while (lo < hi) {
		int md = (lo+hi)/2;

		if (check (md)) {
			hi = md;
		} else {
			lo = md+1;
		}
	}

	printf ("%d\n", lo);
}