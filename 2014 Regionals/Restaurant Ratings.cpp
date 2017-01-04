#include <cstdio>

#define ll long long

const int N = 15,SUM = 45;

int n,x[N];
ll C[SUM][SUM] = {0};

int main () {
	C[0][0] = 1;
	for (int i = 1;i < SUM;i ++) {
		C[i][0] = C[i-1][0];
		for (int j = 1;j < SUM;j ++) {
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}

	while (scanf ("%d", &n) == 1 and n != 0) {
		int sum = 0;
		for (int i = 0;i < n;i ++) {
			scanf ("%d", &x[i]);
			sum += x[i];
		}

		ll ans = 1;
		for (int i = 0;i < sum;i ++) {
			ans += C[i+n-1][i];
		}
		for (int i = 0;i < n-1;i ++) {
			for (int j = 0;j < x[i];j ++) {
				ans += C[sum-j+n-i-2][sum-j];
			}
			sum -= x[i];
		}
		printf ("%lld\n", ans);
	}
}