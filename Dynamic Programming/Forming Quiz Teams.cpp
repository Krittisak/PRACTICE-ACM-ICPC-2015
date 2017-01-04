#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 16;
const double inf = 1e5;

int n;
double x[N],y[N];
char temp[30];
double dp[1<<N];

inline double dist (int i, int j) {
	return sqrt ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

inline double solve (int s) {
	if (dp[s] == inf) {
		for (int i = 0;i < n;i ++) {
			if ((s>>i)&1) {
				for (int j = i+1;j < n;j ++) {
					if ((s>>j)&1) {
						dp[s] = min (dp[s], solve (s^(1<<i)^(1<<j))+dist (i, j));
					}
				}
			}
		}
	}

	return dp[s];
}

int main () {
	int Case = 0;
	while (scanf ("%d", &n) == 1 and n != 0) {
		n += n;
		for (int i = 0;i < n;i ++) {
			scanf ("%s %lf %lf\n", temp, &x[i], &y[i]);
		}

		for (int i = (1<<n)-1;i >= 0;i --) {
			dp[i] = inf;
		}
		dp[0] = 0;

		printf ("Case %d: %.2lf\n", ++ Case, solve ((1<<n)-1));
	}
}