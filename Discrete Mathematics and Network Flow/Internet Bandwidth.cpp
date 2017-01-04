#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

int n,s,t,m;
int f[N][N];
bool use[N];
vector<int> V[N];

inline bool ford (int u, int t, int lim) {
	if (u == t) {
		return true;
	}
	use[u] = true;
	for (int i = 0;i < V[u].size ();i ++) {
		int v = V[u][i];
		if (not use[v] and f[u][v] >= lim) {
			if (ford (v, t, lim)) {
				f[u][v] -= lim;
				f[v][u] += lim;

				return true;
			}
		}
	}
	return false;
}

inline int maxFlow (int lim) {
	int mf = 0;
	for (int i = 1;i <= n;i ++) {
		use[i] = false;
	}
	while (ford (s, t, lim)) {
		mf += lim;
		for (int i = 1;i <= n;i ++) {
			use[i] = false;
		}
	}
	return mf;
}

inline int solve () {
	int mf = 0;
	for (int i = 512;i >= 1;i >>= 1) {
		mf += maxFlow (i);
	}
	return mf;
}

int main () {
	int test = 0;
	while (scanf ("%d", &n) == 1 and n != 0) {
		scanf ("%d %d %d", &s, &t, &m);

		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= n;j ++) {
				f[i][j] = 0;
			}
			V[i].clear ();
		}

		for (int i = 0;i < m;i ++) {
			int u,v,c;
			scanf ("%d %d %d", &u, &v, &c);
			V[u].push_back (v);
			V[v].push_back (u);

			f[u][v] += c;
			f[v][u] += c;
		}

		printf ("Network %d\n", ++ test);
		printf ("The bandwidth is %d.\n\n", solve ());
	}
}