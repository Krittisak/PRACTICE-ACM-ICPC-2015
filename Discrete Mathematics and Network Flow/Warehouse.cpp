#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

const int N = 18,H = 43,W = 43;
const int inf = -1u/2;

int h,w;
int f[H*W][H*W],c[H*W][H*W];
int id[H*W][H*W];
char _s[H][W];
int s,t,nb,nx;
pii q[H*W];
int dp[H][W];
struct node {
	int v,w,p;
	node (int _v, int _w, int _p = -1) {
		v = _v;
		w = _w;
		p = _p;
	}
	inline bool operator < (const node &a) const {
		return w > a.w;
	}
} ;
priority_queue<node> Q;
int D[H*W],p[H*W];

inline bool inBound (pii x) {
	int a = x.first,b = x.second;
	return 0 <= a and a < h and 0 <= b and b < w and _s[a][b] != '#';
}

inline void bfs (int a, int b) {
	for (int i = 0;i < h;i ++) {
		for (int j = 0;j < w;j ++) {
			dp[i][j] = inf;
		}
	}

	int ff = 0,r = -1;
	q[++ r] = pii (a, b);
	dp[a][b] = 0;
	while (ff <= r) {
		pii u = q[ff ++];
		int t = dp[u.first][u.second]+1;
		pii v = pii (u.first, u.second-1);
		if (inBound (v) and dp[v.first][v.second] > t) {
			dp[v.first][v.second] = t;
			q[++ r] = v;
		}
		v = pii (u.first, u.second+1);
		if (inBound (v) and dp[v.first][v.second] > t) {
			dp[v.first][v.second] = t;
			q[++ r] = v;
		}
		v = pii (u.first-1, u.second);
		if (inBound (v) and dp[v.first][v.second] > t) {
			dp[v.first][v.second] = t;
			q[++ r] = v;
		}
		v = pii (u.first+1, u.second);
		if (inBound (v) and dp[v.first][v.second] > t) {
			dp[v.first][v.second] = t;
			q[++ r] = v;
		}
	}

	for (int i = 0;i < h;i ++) {
		for (int j = 0;j < w;j ++) {
			if (_s[i][j] == 'X' and dp[i][j] < inf) {
				int u = id[a][b]+1,v = id[i][j]+nb+1;
				f[u][v] = 1;
				c[u][v] = dp[i][j];
				c[v][u] = -dp[i][j];
			}
		}
	}
}

inline int maxFlow () {
	int ans = 0;
	int r = 0;
	do {
		for (int i = 0;i <= t;i ++) {
			D[i] = inf;
		}
		Q.push (node (s, 0));

		while (not Q.empty ()) {
			node u = Q.top ();
			Q.pop ();

			if (u.w < D[u.v]) {
				D[u.v] = u.w;
				p[u.v] = u.p;
				for (int i = 0;i <= t;i ++) {
					if (f[u.v][i] > 0 and u.w+c[u.v][i] < D[i]) {
						Q.push (node (i, u.w+c[u.v][i], u.v));
					}
				}
			}
		}
		if (D[t] == inf) {
			break;
		}
		ans += D[t];
		int v = t,u = p[t],flow = inf;
		while (u != -1) {
			flow = min (flow, f[u][v]);
			v = u;
			u = p[u];
		}
		v = t,u = p[t];
		while (u != -1) {
			f[u][v] -= flow;
			f[v][u] += flow;
			v = u;
			u = p[u];
		}
		r ++;
	} while (true) ;
	return ans;
}

int main () {
	int test;
	scanf ("%d", &test);

	while (test --) {
		scanf ("%d %d", &h, &w);

		nb = nx = 0;
		for (int i = 0;i < h;i ++) {
			scanf ("%s", _s[i]);
			for (int j = 0;j < w;j ++) {
				if (_s[i][j] == 'B') {
					id[i][j] = nb ++;
				} else if (_s[i][j] == 'X') {
					id[i][j] = nx ++;
				}
			}
		}

		s = 0;
		t = nb+nx+1;

		for (int i = 0;i <= t;i ++) {
			for (int j = 0;j <= t;j ++) {
				f[i][j] = 0;
				c[i][j] = 0;
			}
		}

		for (int i = 0;i < h;i ++) {
			for (int j = 0;j < w;j ++) {
				if (_s[i][j] == 'B') {
					f[s][id[i][j]+1] = 1;
					bfs (i, j);
				} else if (_s[i][j] == 'X') {
					f[id[i][j]+nb+1][t] = 1;
				}
			}
		}

		printf ("%d\n", maxFlow ());
	}
}