#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;

int n,l;
int x[N][N],dp[N][N];
struct abc {
	int x,a,b;
} p[N*N];

inline bool comp (abc a, abc b) {
	return a.x < b.x;
}

int main () {
	int test;
	scanf ("%d", &test);

	for (int Case = 0;Case < test;Case ++) {
		scanf ("%d %d", &n, &l);

		int np = 0;
		for (int i = 0;i < n;i ++) {
			for (int j = 0;j < n;j ++) {
				scanf ("%d", &x[i][j]);
				p[np].x = x[i][j];
				p[np].a = i;
				p[np].b = j;
				np ++;

				dp[i][j] = -1;
			}
		}
		sort (p, p+np, comp);

		dp[0][0] = x[0][0];

		for (int k = 0;k < np;k ++) {
			int i = p[k].a,j = p[k].b;
			if (dp[i][j] >= 0) {
				for (int c = 1;c <= l;c ++) {
					int a,b;
					a = i-c; b = j;
					if (0 <= a and a < n and 0 <= b and b < n and x[a][b] > x[i][j]) {
						dp[a][b] = max (dp[a][b], dp[i][j]+x[a][b]);
					}

					a = i+c; b = j;
					if (0 <= a and a < n and 0 <= b and b < n and x[a][b] > x[i][j]) {
						dp[a][b] = max (dp[a][b], dp[i][j]+x[a][b]);
					}

					a = i; b = j+c;
					if (0 <= a and a < n and 0 <= b and b < n and x[a][b] > x[i][j]) {
						dp[a][b] = max (dp[a][b], dp[i][j]+x[a][b]);
					}

					a = i; b = j-c;
					if (0 <= a and a < n and 0 <= b and b < n and x[a][b] > x[i][j]) {
						dp[a][b] = max (dp[a][b], dp[i][j]+x[a][b]);
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0;i < n;i ++) {
			for (int j = 0;j < n;j ++) {
				ans = max (ans, dp[i][j]);
			}
		}
		if (Case > 0) {
			printf ("\n");
		}
		printf ("%d\n", ans);
	}
}