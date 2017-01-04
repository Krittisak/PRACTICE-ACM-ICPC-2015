#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 1e3+10;

int n;
ll C[N][N] = {0};

inline ll solve (int n) {
	if (n < 4 or n%2 == 1) {
		return 0;
	} else if (n == 4) {
		return 1;
	} else {
		int k = (n-4)/2;
		return C[n-k-1][k-1]+C[n-k][k];
	}
}

int main () {
	C[0][0] = 1;
	for (int i = 1;i < N;i ++) {
		C[i][0] = 1;
		for (int j = 1;j < N;j ++) {
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}

	int test = 0;
	while (scanf ("%d", &n) == 1 and n != 0) {
		printf ("Case %d: %lld\n", ++ test, solve (n));
	}
}