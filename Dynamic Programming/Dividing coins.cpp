#include <cstdio>

const int N = 110,M = 510*110;

int n;
int dp[2][M+M];

int main () {
	int t;
	scanf ("%d", &t);

	for (int z = 0;z < t;z ++) {
		for (int i = 0;i < M+M;i ++) {
			dp[0][i] = dp[1][i] = -1;
		}
		dp[0][M] = 0;

		scanf ("%d", &n);
		for (int i = 0;i < n;i ++) {
			int x;
			scanf ("%d", &x);
			for (int j = 0;j < M+M;j ++) {
				if (dp[i&1][j] == i) {
					dp[i+1&1][j+x] = dp[i+1&1][j-x] = i+1;
				}
			}
		}

		int ans;
		for (ans = 0;ans < M and dp[n&1][M-ans] != n and dp[n&1][M+ans] != n;ans ++) ;
		printf ("%d\n", ans);
	}
}