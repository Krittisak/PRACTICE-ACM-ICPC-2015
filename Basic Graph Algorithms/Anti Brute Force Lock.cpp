#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 510;
const int inf = -1u/2;

int n,m;
char s[N][5];
struct edge {
	int u,v,w;

	edge (int _u = 0, int _v = 0, int _w = 0) {
		u = _u;
		v = _v;
		w = _w;
	}
} e[N*N];

inline bool comp (edge a, edge b) {
	return a.w < b.w;
}

inline int diff (int a, int b) {
	int c = (a-b+10)%10;
	return min (c, 10-c);
}

inline int compute (char a[], char b[]) {
	int sum = 0;
	for (int i = 0;i < 4;i ++) {
		sum += diff (a[i]-'0', b[i]-'0');
	}
	return sum;
}

int p[N];
inline int find (int u) {
	if (u == p[u]) {
		return u;
	} else {
		return p[u] = find (p[u]);
	}
}

int main () {
	int t;
	scanf ("%d", &t);

	while (t --) {
		scanf ("%d", &n);
		for (int i = 1;i <= n;i ++) {
			scanf ("%s", s[i]);
			p[i] = i;
		}

		m = 0;
		for (int i = 1;i <= n;i ++) {
			for (int j = i+1;j <= n;j ++) {
				e[m ++] = edge (i, j, compute (s[i], s[j]));
			}
		}

		sort (e, e+m, comp);

		int ans = inf;
		char init[] = "0000";
		for (int i = 1;i <= n;i ++) {
			ans = min (ans, compute (init, s[i]));
		}

		for (int i = 0;i < m;i ++) {
			int u = e[i].u,v = e[i].v;
			if (find (u) != find (v)) {
				ans += e[i].w;
				p[find (u)] = find (v);
			}
		}
		printf ("%d\n", ans);
	}
}