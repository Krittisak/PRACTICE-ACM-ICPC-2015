#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e3+10,C = 110;
const int inf = -1u/2;

int n,m;
int p[N],dp[N][C];
struct edge {
	int v,w,c;
	edge (int _v = 0, int _w = 0, int _c = 0) {
		v = _v;
		w = _w;
		c = _c;
	}

	inline bool operator < (const edge &a) const {
		return w > a.w;
	}
} ;
vector<edge> V[N];
priority_queue<edge> q;

inline int dij (int c, int s, int e) {
	for (int i = 0;i < n;i ++) {
		for (int j = 0;j <= c;j ++) {
			dp[i][j] = inf;
		}
	}
	q.push (edge (s, 0, 0));
	while (not q.empty ()) {
		edge u = q.top ();
		q.pop ();

		if (u.w < dp[u.v][u.c]) {
			dp[u.v][u.c] = min (dp[u.v][u.c], u.w);

			if (u.c+1 <= c) {
				q.push (edge (u.v, u.w+p[u.v], u.c+1));
			}
			for (int i = 0;i < V[u.v].size ();i ++) {
				edge v = V[u.v][i];
				if (u.c >= v.w) {
					q.push (edge (v.v, u.w, u.c-v.w));
				}
			}
		}
	}

	return dp[e][0];
}

int main () {
	scanf ("%d %d", &n, &m);

	for (int i = 0;i < n;i ++) {
		scanf ("%d", &p[i]);
	}

	for (int i = 0;i < m;i ++) {
		int u,v,w;
		scanf ("%d %d %d", &u, &v, &w);

		V[u].push_back (edge (v, w));
		V[v].push_back (edge (u, w));
	}

	int q;
	scanf ("%d", &q);
	while (q --) {
		int c,s,e;
		scanf ("%d %d %d", &c, &s, &e);

		int ans = dij (c, s, e);
		if (ans == inf) {
			printf ("impossible\n");
		} else {
			printf ("%d\n", ans);
		}
	}
}