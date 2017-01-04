#include <cstdio>

#define ll long long

inline ll abs (ll a) {
	return a < 0 ? -a : a;
}

int main () {
	int n;
	while (scanf ("%d", &n) == 1 and n) {
		ll ans = 0,sum = 0;
		for (int i = 0;i < n;i ++) {
			int x;
			scanf ("%d", &x);

			sum += x;
			ans += abs (sum);
		}
		printf ("%lld\n", ans);
	}
}