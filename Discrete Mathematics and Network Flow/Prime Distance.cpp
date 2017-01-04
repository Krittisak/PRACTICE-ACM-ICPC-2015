#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

const ll inf = -1u/2;

bool use[1000010] = {0};
int p[5000],c = 0;
ll l,r;

inline ll F (ll i) {
	if (l%i == 0) {
		return max (l, i*i);
	} else {
		return max (l+i-(l%i), i*i);
	}
}

int main () {
	int lim = sqrt (inf);
	lim = sqrt (inf);
	for (int i = 2;i <= lim;i ++) {
		if (use[i] == 0) {
			p[c ++] = i;
			for (int j = i*i;j <= lim;j += i) {
				use[j] = 1;
			}
		}
	}

	while (scanf ("%lld %lld", &l, &r) == 2) {
		for (int i = 0;i <= r-l;i ++) {
			use[i] = 0;
		}
		for (int i = 0;i < c;i ++) {
			int k = p[i];
			for (ll j = F (k);j <= r;j += k) {
				use[j-l] = 1;
			}
		}
		int k = -1;
		int a = 0,b = inf,c = 0,d = 0;
		for (int i = 0;i <= r-l;i ++) {
			if (use[i] == 0 and i+l > 1) {
				if (k != -1) {
					if (i-k < b-a) {
						a = k+l;
						b = i+l;
					}
					if (i-k > d-c) {
						c = k+l;
						d = i+l;
					}
				}
				k = i;
			}
		}
		if (a == 0) {
			printf ("There are no adjacent primes.\n");
		} else {
			printf ("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
		}
	}
}