#include <cstdio>

const int N = 2e5+10;

int n,x[N],f[N];

inline void update (int a, int b) {
	for (int i = a;i < N;i += i&(-i)) {
		f[i] += b;
	}
}

inline int query (int a) {
	int sum = 0;
	for (int i = a;i > 0;i -= i&(-i)) {
		sum += f[i];
	}
	return sum;
}

int main () {
	int Case = 0;
	while (scanf ("%d", &n) == 1 and n != 0) {
		for (int i = 1;i <= n;i ++) {
			f[i] = 0;
		}

		for (int i = 1;i <= n;i ++) {
			scanf ("%d", &x[i]);
			update (i, x[i]);
		}

		if (Case > 0) {
			printf ("\n");
		}
		printf ("Case %d:\n", ++ Case);

		while (true) {
			char s[5];
			scanf ("%s", s);
			if (s[0] == 'M') {
				int a,b;
				scanf ("%d %d", &a, &b);
				printf ("%d\n", query (b)-query (a-1));
			} else if (s[0] == 'S') {
				int a,b;
				scanf ("%d %d", &a, &b);

				update (a, b-x[a]);
				x[a] = b;
			} else {
				break;
			}
		}
	}
}