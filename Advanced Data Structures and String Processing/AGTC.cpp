#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

int n,m;
char a[N],b[N];
int dp[N][N];

int main () {
	for (int i = 0;i < N;i ++) {
		dp[0][i] = dp[i][0] = i;
	}

	while (scanf ("%d", &n) == 1) {
		scanf ("%s %d %s", a+1, &m, b+1);

		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= m;j ++) {
				if (a[i] == b[j]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] = min (min (dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
				}
			}
		}

		printf ("%d\n", dp[n][m]);
	}
}