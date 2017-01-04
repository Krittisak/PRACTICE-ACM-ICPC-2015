#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

const int N = 1e6+10,K = 20,inf = -1u/2;

int n,k;
pii a[N];
int dp[N][K];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 0;i < k;i ++) {
		scanf ("%d %d", &a[i].first, &a[i].second);

		if (a[i].second < a[i].first) {
			a[i].second += n;
		}
		a[i].second ++;
	}

	sort (a, a+k);

	int ans = inf;
	for (int i = 0,f = 0;i < k;i ++) {
		while (f < i and a[f].second < a[i].first) {
			f ++;
		}

		dp[i][0] = f;
		for (int j = 1,p = f;j < K;j ++) {
			dp[i][j] = dp[p][j-1];
			p = dp[p][j-1];
		}

		int sum = 1,u = i;
		for (int j = K-1;j >= 0;j --) {
			if (a[i].second-a[dp[u][j]].first < n) {
				sum += 1<<j;
				u = dp[u][j];
			}
		}
		if (a[i].second-a[u].first < n) {
			u = dp[u][0];
			sum ++;
		}
		if (a[i].second-a[u].first >= n) {
			ans = min (ans, sum);
		}
	}

	if (ans == inf) {
		printf ("impossible\n");
	} else {
		printf ("%d\n", ans);
	}
}