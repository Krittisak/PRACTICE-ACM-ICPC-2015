#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 110;
const int inf = -1u/2;

#define pii pair<int, int>

int n,m;
pii p1[N],p2[N];
int c[N+N][N+N],e[N+N][N+N],s,t;
bool use[N+N];
int ans[N];

inline double Dist (pii a, pii b) {
	return sqrt ((double)(a.first-b.first)*(a.first-b.first)+(double)(a.second-b.second)*(a.second-b.second));
}

inline bool check (pii a, pii b, pii c) {
	return Dist (a, c)+Dist (c, b) <= 2*Dist (a, b);
}

inline int augment (int u, int t, int lim = inf) {
	if (u == t) {
		return lim;
	}
	use[u] = true;
	for (int v = 0;v <= t;v ++) {
		if (not use[v] and c[u][v] > 0) {
			if (int f = augment (v, t, min (c[u][v], lim))) {
				c[u][v] -= f;
				c[v][u] += f;

				return f;
			}
		}
	}
	return 0;
}

inline int ford () {
	int mf = 0;
	for (int i = 0;i <= t;i ++) {
		use[i] = false;
	}
	while (int f = augment (s, t)) {
		mf += f;
		for (int i = 0;i <= t;i ++) {
			use[i] = false;
		}
	}
	return mf;
}

int main () {
	int test;
	scanf ("%d", &test);

	for (int Case = 0;Case < test;Case ++) {
		scanf ("%d %d", &n, &m);

		s = 0;
		t = n+m;
		for (int i = 0;i <= t;i ++) {
			for (int j = 0;j <= t;j ++) {
				c[i][j] = e[i][j] = 0;
			}
		}

		for (int i = 0;i < n;i ++) {
			scanf ("%d %d", &p1[i].first, &p1[i].second);

			ans[i] = -1;
			if (i < n-1) {
				c[s][i+1] = 1;
			}
		}
		for (int i = 0;i < m;i ++) {
			scanf ("%d %d", &p2[i].first, &p2[i].second);

			c[i+n][t] = 1;
		}

		for (int i = 0;i < n-1;i ++) {
			for (int j = 0;j < m;j ++) {
				if (check (p1[i], p1[i+1], p2[j])) {
					c[i+1][j+n] = 1;
					e[i+1][j+n] = 1;
				}
			}
		}

		int mf = ford ();
		for (int i = 1;i < n;i ++) {
			for (int j = n;j < t;j ++) {
				if (e[i][j] == 1 and c[i][j] == 0) {
					ans[i-1] = j-n;
					break;
				}
			}
		}

		if (Case > 0) {
			printf ("\n");
		}
		printf ("%d\n", n+mf);
		for (int i = 0;i < n;i ++) {
			if (i > 0) {
				printf (" ");
			}
			printf ("%d %d", p1[i].first, p1[i].second);
			if (ans[i] != -1) {
				printf (" %d %d", p2[ans[i]].first, p2[ans[i]].second);
			}
		}
		printf ("\n");
	}
}