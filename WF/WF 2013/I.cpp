#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 510,inf = -1u/2;

int x[N][N];
int t[N],L[N],R[N];
pii s[N];

inline ll solve (int a, int b, int n, int m) {
	ll ans = 0;
	for (int i = 0;i < n;i ++) {
		for (int k = 0;k < m;k ++) {
			t[k] = inf;
		}

		for (int j = i;j < n and j-i+1 <= a;j ++) {
			int f = -1;
			s[++ f] = pii (-1, -1);
			for (int k = 0;k < m;k ++) {
				t[k] = min (t[k], x[j][k]);

				while (f >= 0 and s[f].first >= t[k]) {
					f --;
				}
				s[++ f] = pii (t[k], k);

				L[k] = s[f-1].second+1;
			}

			f = -1;
			s[++ f] = pii (-1, m);
			for (int k = m-1;k >= 0;k --) {
				while (f >= 0 and s[f].first >= t[k]) {
					f --;
				}
				s[++ f] = pii (t[k], k);

				R[k] = s[f-1].second-1;
			}

			for (int k = 0;k < m;k ++) {
				int w = j-i+1,l = min (b, R[k]-L[k]+1);
				ll h = ((ll)t[k]*n*m-1)/(n*m-w*l);
				ans = max (ans, h*w*l);
			}
		}
	}
	return ans;
}

int main () {
	int a,b,n,m;
	scanf ("%d %d %d %d", &a, &b, &n, &m);
	for (int i = 0;i < n;i ++) {
		for (int j = 0;j < m;j ++) {
			scanf ("%d", &x[i][j]);
		}
	}

	printf ("%lld\n", max (solve (a, b, n, m), solve (b, a, n, m)));
}