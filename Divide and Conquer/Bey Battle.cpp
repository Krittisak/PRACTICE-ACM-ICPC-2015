#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
const int inf = -1u/4;

int n;
struct point {
	int x,y;
} p[N];
int X[N],nx;
struct tree {
	int l,r,t;
	bool u;
	int left,right;
	tree (int _l = 0, int _r = 0) {
		l = _l;
		r = _r;
		t = -inf;
		u = false;
		left = right = -1;
	}
} T[N+N];
int idx;

inline bool comp (point a, point b) {
	return a.y < b.y;
}

inline void kajai (int i) {
	if (T[i].u) {
		T[i].u = false;
		if (T[i].left != -1) {
			T[T[i].left].t = max (T[T[i].left].t, T[i].t);
			T[T[i].left].u = true;
		}
		if (T[i].right != -1) {
			T[T[i].right].t = max (T[T[i].right].t, T[i].t);
			T[T[i].right].u = true;
		}
	}
}

inline int query (int l, int r, int i = 0) {
	kajai (i);
	if (T[i].r < l or T[i].l > r) {
		return -inf;
	} else if (l <= T[i].l and T[i].r <= r) {
		return T[i].t;
	} else {
		return max (query (l, r, T[i].left), query (l, r, T[i].right));
	}
}

inline int update (int l, int r, int t, int i = 0) {
	kajai (i);
	if (T[i].r < l or T[i].l > r) {
		return T[i].t;
	} else if (l <= T[i].l and T[i].r <= r) {
		T[i].u = true;
		T[i].t = max (T[i].t, t);
	} else {
		T[i].t = max (update (l, r, t, T[i].left), update (l, r, t, T[i].right));
	}
	return T[i].t;
}

inline void clear (int i = 0) {
	if (i != -1) {
		T[i].t = -inf;
		T[i].u = false;
		clear (T[i].left);
		clear (T[i].right);
	}
}

inline void build (int l, int r, int i = 0) {
	T[i] = tree (l, r);
	if (l < r) {
		int m = (l+r) >> 1;
		T[i].left = ++ idx;
		T[i].right = ++ idx;
		build (l, m, T[i].left);
		build (m+1, r, T[i].right);
	}
}

inline bool check (int md) {
	clear ();
	for (int i = 0;i < n;i ++) {
		int a = lower_bound (X, X+nx, p[i].x-md+1)-X;
		int b = upper_bound (X, X+nx, p[i].x)-X-1;
		int k = query (a, b);
		if (p[i].y-k < md) {
			return false;
		}
		update (a, b, p[i].y);
	}	

	return true;
}

int main () {
	while (scanf ("%d", &n) == 1) {
		for (int i = 0;i < n;i ++) {
			scanf ("%d %d", &p[i].x, &p[i].y);
			X[i] = p[i].x;
		}
		nx = n;

		sort (p, p+n, comp);

		sort (X, X+nx);
		nx = unique (X, X+nx)-X;

		idx = 0;
		build (0, nx-1);

		int lo = 1,hi = 2e6;
		while (lo < hi) {
			int md = (lo+hi+1) >> 1;

			if (check (md)) {
				lo = md;
			} else {
				hi = md-1;
			}
		}
		printf ("%d\n", lo);
	}
}