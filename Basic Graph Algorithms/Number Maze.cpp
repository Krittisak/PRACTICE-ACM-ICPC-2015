#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e3+10;
const int inf = -1u/2;

int n,m;
int x[N][N],dp[N][N];
struct node {
	int i,j,k;

	node (int _i, int _j, int _k) {
		i = _i;
		j = _j;
		k = _k;
	}

	inline bool operator < (const node &a) const {
		return k > a.k;
	}
} ;
priority_queue<node> q;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline int dij () {
	q.push (node (1, 1, 0));
	while (not q.empty ()) {
		node u = q.top ();
		q.pop ();

		u.k += x[u.i][u.j];
		if (u.k < dp[u.i][u.j]) {
			dp[u.i][u.j] = u.k;
			for (int i = 0;i < 4;i ++) {
				node v (u.i+d[i][0], u.j+d[i][1], u.k);
				if (1 <= v.i and v.i <= n and 1 <= v.j and v.j <= m and v.k < dp[v.i][v.j]) {
					q.push (v);
				}
			}
		}
	}
	return dp[n][m];
}

int main () {
	int t;
	scanf ("%d", &t);

	while (t --) {
		scanf ("%d %d", &n, &m);

		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= m;j ++) {
				scanf ("%d", &x[i][j]);
				dp[i][j] = inf;
			}
		}

		printf ("%d\n", dij ());
	}
}