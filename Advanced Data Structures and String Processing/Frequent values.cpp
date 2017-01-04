#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5+10,K = 18;

#define pii pair<int, int>

int n,Q;
int x[N],D[K][N];
pii L[K][N],R[K][N];

int main () {
	while (scanf ("%d", &n) == 1 and n != 0) {
		scanf ("%d", &Q);
		for (int i = 0;i < n;i ++) {
			scanf ("%d", &x[i]);
		}

		for (int i = 0;i < n;i ++) {
			D[0][i] = 1;
			L[0][i] = R[0][i] = pii (1, x[i]);
		}
		for (int k = 1;k < K;k ++) {
			for (int i = 0;i < n;i ++) {
				int j = i+(1<<(k-1));
				if (j < n) {
					if (R[k-1][i].second == L[k-1][j].second) {
						L[k][i] = L[k-1][i];
						if (L[k-1][i].second == L[k-1][j].second) {
							L[k][i].first += L[k-1][j].first;
						}
						R[k][i] = R[k-1][j];
						if (R[k-1][i].second == R[k-1][j].second) {
							R[k][i].first += R[k-1][i].first;
						}
						D[k][i] = max (max (D[k-1][i], D[k-1][j]), R[k-1][i].first+L[k-1][j].first);
					} else {
						L[k][i] = L[k-1][i];
						R[k][i] = R[k-1][j];
						D[k][i] = max (D[k-1][i], D[k-1][j]);
					}
				} else {
					D[k][i] = D[k-1][i];
					L[k][i] = L[k-1][i];
					R[k][i] = R[k-1][i];
				}
			}
		}

		while (Q --) {
			int l,r;
			scanf ("%d %d", &l, &r);
			l --;
			r --;

			int k = K;
			int a = 0;
			pii b = pii (0, x[l]),c = pii (0, x[l]);
			while (l <= r) {
				while (l+(1<<(-- k))-1 > r) ;

				if (c.second == L[k][l].second) {
					a = max (max (a, D[k][l]), c.first+L[k][l].first);
					pii t = c;
					c = R[k][l];
					if (t.second == R[k][l].second) {
						c.first += t.first;
					}
					b = b;
					if (b.second == L[k][l].second) {
						b.first += L[k][l].first;
					}
				} else {
					b = b;
					c = R[k][l];
					a = max (a, D[k][l]);
				}
				l += (1<<k);
			}
			printf ("%d\n", a);
		}
	}
}