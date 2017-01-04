#include <cstdio>

#define ll long long

const int N = 31;

int T;
ll C[N][N] = {0};

int main () {
	C[0][0] = 1;
	for (int i = 1;i < N;i ++) {
		C[i][0] = C[i-1][0];
		for (int j = 1;j < N;j ++) {
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}

	scanf ("%d", &T);

	for (int i = 0;i < T;i ++) {
		int n,m;
		scanf ("%d %d", &n, &m);

		printf ("%lld %lld\n", C[n][m-1], C[n-1][m-1]);
	}
}