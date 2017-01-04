#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 510,inf = -1u/4;

int n,x[N];
int dp1[N],dp2[N][N];
int noi[N][N],sum[N][N] = {0};

inline int rec2 (int l, int r) {
	if (dp2[l][r] == -1) {
		dp2[l][r] = inf;
		for (int i = l;i < r;i ++) {
			int a = noi[l][i],b = noi[i+1][r];
			int cnt = r-l+1;
			if (a < b) {
				cnt -= sum[l][b-1]-sum[i+1][b-1];
			} else {
				cnt -= sum[i+1][a-1]-sum[r+1][a-1];
			}

			dp2[l][r] = min (dp2[l][r], rec2 (l, i)+rec2 (i+1, r)+cnt);
		}
	}

	return dp2[l][r];
}

inline int rec1 (int n) {
	if (dp1[n] == -1) {
		int c[N],mak = -inf;
		for (int i = 0;i < N;i ++) {
			c[i] = 0;
		}

		dp1[n] = inf;
		for (int i = n;i >= 1;i --) {
			c[x[i]] ++;
			if (c[x[i]] > 1) {
				break;
			}
			mak = max (mak, x[i]);

			if (mak == n-i+1) {
				dp1[n] = min (dp1[n], rec1 (i-1)+rec2 (i, n));
			}
		}
	}

	return dp1[n];
}

int main () {
	scanf ("%d", &n);

	for (int i = 1;i <= n;i ++) {
		scanf ("%d", &x[i]);

		dp1[i] = -1;
		for (int j = 1;j <= n;j ++) {
			dp2[i][j] = -1;
		}
		dp2[i][i] = 0;
	}
	dp1[0] = 0;

	for (int i = 1;i <= n;i ++) {
		noi[i][i] = x[i];
		for (int j = i+1;j <= n;j ++) {
			noi[i][j] = min (noi[i][j-1], x[j]);
		}

		for (int j = i;j <= n;j ++) {
			sum[i][x[j]] ++;
		}
		for (int j = 1;j <= n;j ++) {
			sum[i][j] += sum[i][j-1];
		}
	}

	rec1 (n);

	if (dp1[n] == inf) {
		printf ("impossible\n");
	} else {
		printf ("%d\n", dp1[n]);
	}
}