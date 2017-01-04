#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 150;

inline ll gcd (ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd (b, a%b);
	}
}

inline ll lcm (ll a, ll b) {
	return (a/gcd (a, b))*b;
}

struct rat {
	ll a,b;
	rat (ll _a = 0, ll _b = 1) {
		ll g = gcd (_a, _b);
		a = _a/g;
		b = _b/g;
	}
} dp[30][N];

inline rat operator + (const rat &a, const rat &b) {
	ll l = lcm (a.b, b.b);
	return rat (a.a*(l/a.b)+b.a*(l/b.b), l);
}

inline rat operator - (const rat &a, const rat &b) {
	ll l = lcm (a.b, b.b);
	return rat (a.a*(l/a.b)-b.a*(l/b.b), l);
}

inline rat operator * (const rat &a, const rat &b) {
	return rat (a.a*b.a, a.b*b.b);
}

int main () {
	for (int i = 0;i < N;i ++) {
		dp[0][i] = rat (1, 1);
	}
	for (int i = 1;i <= 24;i ++) {
		for (int j = 0;j < N;j ++) {
			for (int k = 1;k <= 6 and j-k >= 0;k ++) {
				dp[i][j] = dp[i][j]+(dp[i-1][j-k]*rat (1, 6));
			}
		}
	}

	int n,k;
	while (scanf ("%d %d", &n, &k) == 2 and not (n == 0 and k == 0)) {
		if (k <= n) {
			printf ("1\n");
		} else if (k > 6*n) {
			printf ("0\n");
		} else {
			rat ans = rat (1, 1)-dp[n][k-1];
			printf ("%lld/%lld\n", ans.a, ans.b);
		}
	}
}