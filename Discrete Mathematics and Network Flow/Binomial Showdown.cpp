#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

inline ll gcd (ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd (b, a%b);
	}
}

inline ll solve (ll n, ll k) {
	ll a = 1,b = 1;
	for (int i = 0;i < k;i ++) {
		ll x = k-i,y = n-k+i+1;
		ll g1 = gcd (a, x),g2 = gcd (b, y);
		a = (a/g1)*(y/g2);
		b = (b/g2)*(x/g1);
	}
	return a/b;
}

int main () {
	ll n,k;
	while (scanf ("%lld %lld", &n, &k) == 2 and not (n == 0 and k == 0)) {
		if (n-k < k) {
			k = n-k;
		}

		printf ("%lld\n", solve (n, k));
	}
}