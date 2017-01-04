#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

int n;
int dp[N][N] = {0};
char s[N];

int main () {
	int t;
	scanf ("%d", &t);
	gets (s);

	while (t --) {
		gets (s);
		for (n = 0;s[n] != 0;n ++) ;

		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= n;j ++) {
				if (s[i-1] == s[n-j]) {
					dp[i][j] = dp[i-1][j-1]+1;
				} else {
					dp[i][j] = max (dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		printf ("%d\n", dp[n][n]);
	}
}