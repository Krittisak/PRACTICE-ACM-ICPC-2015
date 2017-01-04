#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6+10;

int n,dp[N];
char x[N];

inline void KMP () {
	int i = 0,j = dp[0] = -1;
	while (i < n) {
		while (j > -1 and x[i] != x[j]) {
			j = dp[j];
		}
		i ++;
		j ++;
		if (x[i] == x[j]) {
			dp[i] = dp[j];
		} else {
			dp[i] = j;
		}
	}
}

int main () {
	while (scanf ("%s", x) == 1 and x[0] != '.') {
		for (n = 0;x[n] != 0;n ++) ;
		KMP ();
		printf ("%d\n", n/(n-dp[n]));
	}
}