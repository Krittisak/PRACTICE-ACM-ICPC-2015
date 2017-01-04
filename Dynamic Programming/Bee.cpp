#include <cstdio>

const int N = 1e6+10;

#define ll long long

int n;
ll a[N],b[N];

int main () {
	a[0] = 1;
	b[0] = 0;
	for (int i = 1;i < N;i ++) {
		a[i] = 1+b[i-1];
		b[i] = b[i-1]+a[i-1];
	}

	while (scanf ("%d", &n) == 1 and n != -1) {
		printf ("%lld %lld\n", b[n], a[n]+b[n]);
	}
}