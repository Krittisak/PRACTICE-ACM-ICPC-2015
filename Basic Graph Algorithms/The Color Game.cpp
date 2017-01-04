#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;
const int inf = -1u/2;

#define pii pair<int, int>

int n;
int x[N][N],y[N][N];
pii q[N*N];
int f,r;

inline int bfs (int a, int b, int c) {
	f = 0;
	r = -1;
	q[++ r] = pii (min (a, b), max (a, b));
	y[min (a, b)][max (a, b)] = 0;
	while (f <= r) {
		pii u = q[f ++];
		
		if (u.first == c or u.second == c) {
			return y[u.first][u.second];
		}

		if (x[u.first][u.second] > 0) {
			int v = x[u.first][u.second];
			int a = min (v, u.second),b = max (v, u.second);
			if (y[a][b] == inf) {
				y[a][b] = y[u.first][u.second]+1;
				q[++ r] = pii (a, b);
			}
		}

		if (x[u.second][u.first] > 0) {
			int v = x[u.second][u.first];
			int a = min (v, u.first),b = max (v, u.first);
			if (y[a][b] == inf) {
				y[a][b] = y[u.first][u.second]+1;
				q[++ r] = pii (a, b);
			}
		}
	}
	return -1;
}

int main () {
	int Case = 1;
	while (scanf ("%d", &n) == 1 and n != 0) {
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= n;j ++) {
				scanf ("%d", &x[i][j]);
				y[i][j] = inf;
			}
		}

		int a,b,c;
		scanf ("%d %d %d", &a, &b, &c);

		int ans = bfs (a, b, c);
		printf ("Game #%d\n", Case ++);
		if (ans == -1) {
			printf ("Destination is Not Reachable !\n\n");
		} else {
			printf ("Minimum Number of Moves = %d\n\n", ans);
		}
	}
}