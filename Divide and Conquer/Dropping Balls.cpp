#include <cstdio>

int n,m;

int main () {
	int t;
	scanf ("%d", &t);

	while (t --) {
		scanf ("%d %d", &n, &m);
		n --;
		m --;

		int ans = 1;
		for (int i = 0;i < n;i ++) {
			ans <<= 1;
			ans |= (m&1);
			m >>= 1;
		}
		printf ("%d\n", ans);
	}

	scanf ("%d", &t);
}