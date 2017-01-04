#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
bool V[N][N],use[N];

int main () {
	int tt;
	scanf ("%d", &tt);

	for (int Case = 1;Case <= tt;Case ++) {
		scanf ("%d %d", &n, &m);

		for (int i = 1;i <= n;i ++) {
			use[i] = false;
			for (int j = 1;j <= n;j ++) {
				V[i][j] = false;
			}
		}

		for (int i = 0;i < m;i ++) {
			int u,v;
			scanf ("%d %d", &u, &v);
			V[u][v] = V[v][u] = true;
		}

		int ans = 0;
		for (int i = 1;i <= n;i ++) {
			int a = 0,b = 0;
			for (int j = 1;j <= i-1;j ++) {
				if (V[i][j]) {
					if (use[j]) {
						b ++;
					} else {
						a ++;
					}
				}
			}
			if (a > b) {
				use[i] = true;
				ans ++;
			}
		}

		printf ("Case #%d: %d\n", Case, ans);
		bool f = false;
		for (int i = 1;i <= n;i ++) {
			if (use[i]) {
				if (f) {
					printf (" ");
				}
				f = true;
				printf ("%d", i);
			}
		}
		printf ("\n");
	}
}