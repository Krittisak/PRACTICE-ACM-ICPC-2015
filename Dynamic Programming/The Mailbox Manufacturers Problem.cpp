#include <cstdio>
#include <algorithm>

using namespace std;

const int K = 20,N = 120;
const int inf = -1u/4;

int k,n;
int dp[K][N][N];

inline int sumof (int l, int r) {
	return (l+r)*(r-l+1)/2;
}

inline int rec (int k, int l, int r) {
	//printf ("%d %d %d\n", k, l, r);
	if (dp[k][l][r] == inf) {
		if (l > r) {
			dp[k][l][r] = 0;
		} else if (k == 1) {
			dp[k][l][r] = sumof (l, r);
		} else {
			for (int i = l;i <= r;i ++) {
				dp[k][l][r] = min (dp[k][l][r], i+max (rec (k, i+1, r), rec (k-1, l, i-1)));
			}
		}
	}
	return dp[k][l][r];
}

int main () {
	int test;
	scanf ("%d", &test);

	while (test --) {
		scanf ("%d %d", &k, &n);

		for (int i = 0;i <= k;i ++) {
			for (int j = 0;j <= n;j ++) {
				for (int l = 0;l <= n;l ++) {
					dp[i][j][l] = inf;
				}
			}
		}

		printf ("%d\n", rec (k, 1, n));
	}
}