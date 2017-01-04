#include <cstdio>

#define ll long long

ll n,l,u;

int main () {
	while (scanf ("%lld %lld %lld", &n, &l ,&u) == 3) {
		ll ans = 0;
		for (ll i = 32;i >= 0;i --) {
			if (((n>>i)&1) == 0) {
				ans |= (1ll<<i);
				if (ans > u) {
					ans ^= (1ll<<i);
				}
			} else {
				ans |= (1ll<<i);
				if (ans > l) {
					ans ^= (1ll<<i);
				}
			}
		}
		
		printf ("%lld\n", ans);
	}
}