#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 510;

int k,n;
bool c[N];
ll x[N];

inline bool check (int start, ll md, int k) {
	ll c = 0,sum = md;
	for (int i = start;i < n;i ++) {
		if (sum+x[i] > md) {
			c ++;
			sum = 0;
		}
		sum += x[i];
	}
	return c <= k;
}

inline void Print (ll md) {
	int c = 1;
	for (int i = 0;i < n;i ++) {
		if (i) {
			printf (" ");
		}
		printf ("%lld", x[i]);
		if (i+1 < n and check (i+1, md, k-c)) {
			printf (" /");
			c ++;
		}
	}
	printf ("\n");
}

int main () {
	int t;
	scanf ("%d", &t);

	while (t --) {
		ll lo = 0,hi = 0;

		scanf ("%d %d", &n, &k);
		for (int i = 0;i < n;i ++) {
			scanf ("%lld", &x[i]);
			hi += x[i];
			lo = max (lo, x[i]);
			c[i] = false;
		}

		while (lo < hi) {
			ll md = (lo+hi) >> 1;

			if (check (0, md, k)) {
				hi = md;
			} else {
				lo = md+1;
			}
		}

		Print (lo);
	}
}