#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;
const int inf = -1u/4;

int dp[N][N];
bool c[N];

int main () {
	int Case = 1,a,b;
	while (scanf ("%d %d", &a, &b) == 2) {
		if (a == 0 and b == 0) {
			break;
		}

		for (int i = 1;i <= 100;i ++) {
			c[i] = false;
		}

		for (int i = 1;i <= 100;i ++) {
			for (int j = 1;j <= 100;j ++) {
				dp[i][j] = inf;
			}
			dp[i][i] = 0;
		}

		c[a] = c[b] = true;

		dp[a][b] = 1;
		while (scanf ("%d %d", &a, &b) == 2) {
			if (a == 0 and b == 0) {
				break;
			}
			dp[a][b] = 1;
			c[a] = c[b] = true;
		}

		for (int k = 1;k <= 100;k ++) {
			if (c[k]) {
				for (int i = 1;i <= 100;i ++) {
					if (c[i]) {
						for (int j = 1;j <= 100;j ++) {
							if (c[j]) {
								dp[i][j] = min (dp[i][j], dp[i][k]+dp[k][j]);
							}
						}
					}
				}
			}
		}

		double ans = 0,n = 0;
		for (int i = 1;i <= 100;i ++) {
			if (c[i]) {
				for (int j = 1;j <= 100;j ++) {
					if (c[j] and i != j) {
						n ++;
						ans += dp[i][j];
					}
				}
			}
		}
		ans /= n;

		printf ("Case %d: average length between pages = %.3lf clicks\n", Case ++, ans);
	}
}