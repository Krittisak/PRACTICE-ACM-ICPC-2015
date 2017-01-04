#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAX = -1llu/2;
const int N = 63;

int p[N],np = 0,c[N] = {0};
ll f[N][N] = {0};
vector<ll> V;
map<ll, ll> M;

inline void compute (int id, int lt, ll sum = 1, int tot = 0) {
	if (sum > 1) {
		int t = tot;
		ll total = f[t][c[0]];
		t -= c[0];
		for (int i = 1;i < id;i ++) {
			if (total > MAX/f[t][c[i]]) {
				goto f;
			}
			total *= f[t][c[i]];
			t -= c[i];
		}
		if (M.find (total) == M.end ()) {
			M[total] = sum;
		} else {
			M[total] = min (M[total], sum);
		}
		f:;
	}
	for (int i = 1;i <= lt and sum <= MAX/p[id];i ++) {
		sum *= p[id];
		c[id] = i;
		compute (id+1, i, sum, tot+i);
	}
}

int main () {
	for (int i = 0;i < N;i ++) {
		f[i][0] = 1;
		for (int j = 1;j <= i;j ++) {
			if (f[i-1][j-1] == -1 or f[i-1][j] == -1 or f[i-1][j-1] > MAX-f[i-1][j]) {
				f[i][j] = -1;
			} else {
				f[i][j] = f[i-1][j-1]+f[i-1][j];
			}
		}
	}

	for (int i = 2;np < N;i ++) {
		for (int j = 2;j < i;j ++) {
			if (i%j == 0) {
				goto f;
			}
		}
		p[np ++] = i;
		f:;
	}

	M[1] = 2;
	compute (0, N);

	ll n;
	while (scanf ("%lld", &n) == 1) {
		printf ("%lld %lld\n", n, M[n]);
	}
}