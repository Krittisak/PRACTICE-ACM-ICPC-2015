#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e3+10;
const int inf = -1u/4;

int n,m;
int dp[N];
struct edge {
	int u,v,w;
} e[N];

int main () {
	int t;
	scanf ("%d", &t);

	while (t --) {
		scanf ("%d %d", &n, &m);

		for (int i = 0;i < m;i ++) {
			scanf ("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		}

		for (int i = 0;i < n;i ++) {
			dp[i] = inf;
		}

		dp[0] = 0;

		for (int i = 1;i < n;i ++) {
			for (int j = 0;j < m;j ++) {
				dp[e[j].v] = min (dp[e[j].v], dp[e[j].u]+e[j].w);
			}
		}

		bool poss = false;
		for (int i = 0;i < m;i ++) {
			if (dp[e[i].u]+e[i].w < dp[e[i].v]) {
				poss = true;
				break;
			}
		}

		printf ("%s\n", poss ? "possible" : "not possible");
	}
}