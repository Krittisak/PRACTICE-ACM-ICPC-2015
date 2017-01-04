#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1024010;

int n;
int x[N],idx;
struct tree {
	int x,l,r,nl,nr,u;
} T[N+N];

inline void build (int l, int r, int i = 0) {
	T[i].l = l;
	T[i].r = r;
	T[i].u = 0;
	if (l == r) {
		T[i].x = x[l];
	} else {
		T[i].nl = ++ idx;
		T[i].nr = ++ idx;
		int m = (l+r) >> 1;
		build (l, m, T[i].nl);
		build (m+1, r, T[i].nr);
		T[i].x = T[T[i].nl].x+T[T[i].nr].x;
	}
}

inline void upd (int i, int t) {
	if (t == 1) {
		T[i].x = T[i].r-T[i].l+1;
		T[i].u = 1;
	} else if (t == 2) {
		T[i].x = 0;
		T[i].u = 2;
	} else {
		T[i].x = (T[i].r-T[i].l+1)-T[i].x;
		T[i].u = 3-T[i].u;
	}
}

inline void kajai (int i) {
	if (T[i].u != 0) {
		if (T[i].l < T[i].r) {
			upd (T[i].nl, T[i].u);
			upd (T[i].nr, T[i].u);
		}
		T[i].u = 0;
	}
}

inline void update (int l, int r, int t, int i = 0) {
	kajai (i);
	if (r < T[i].l or l > T[i].r) {
		return ;
	} else if (l <= T[i].l and T[i].r <= r) {
		upd (i, t);
	} else {
		update (l, r, t, T[i].nl);
		update (l, r, t, T[i].nr);
		T[i].x = T[T[i].nl].x+T[T[i].nr].x;
	}
}

inline int query (int l, int r, int i = 0) {
	kajai (i);
	if (r < T[i].l or l > T[i].r) {
		return 0;
	} else if (l <= T[i].l and T[i].r <= r) {
		return T[i].x;
	} else {
		return query (l, r, T[i].nl)+query (l, r, T[i].nr);
	}
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int Case = 1;Case <= tt;Case ++) {
		int m;
		scanf ("%d", &m);
		n = 0;
		while (m --) {
			int k;
			char s[60];
			scanf ("%d %s", &k, s);
			for (int i = 0;i < k;i ++) {
				for (int j = 0;s[j] != 0;j ++) {
					x[n ++] = s[j]-'0';
				}
			}
		}

		idx = 0;
		build (0, n-1);

		printf ("Case %d:\n", Case);

		int Q,nQ = 0;
		scanf ("%d", &Q);
		while (Q --) {
			int a,b;
			char s[2];
			scanf ("%s %d %d", s, &a, &b);
			if (s[0] == 'F') {
				update (a, b, 1);
			} else if (s[0] == 'E') {
				update (a, b, 2);
			} else if (s[0] == 'I') {
				update (a, b, 3);
			} else if (s[0] == 'S') {
				printf ("Q%d: %d\n", ++ nQ, query (a, b));
			}
		}
	}
}