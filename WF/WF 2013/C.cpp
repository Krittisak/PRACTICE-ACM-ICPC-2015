#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int N = 25e3+10,inf = -1u/2;

int n,m,c;
vector<pii> V[N];
priority_queue<pii> q;
int dp[N],M[N] = {0};
bool use[N] = {false};

inline void dijikstra () {
	for (int i = 0;i < n;i ++) {
		dp[i] = inf;
	}

	dp[0] = 0;
	q.push (pii (0, 0));
	while (not q.empty ()) {
		pii temp = q.top ();
		q.pop ();

		int w = temp.first,u = temp.second;
		if (w < dp[u]) {
			dp[u] = w;

			for (int i = 0;i < V[u].size ();i ++) {
				int v = V[u][i].second;
				int _w = w+V[u][i].first;

				if (_w < dp[v]) {
					q.push (pii (_w, v));
				}
			}
		}
	}
}

int main () {
	scanf ("%d %d %d", &n, &m, &c);

	for (int i = 0;i < m;i ++) {
		int u,v,w;
		scanf ("%d %d %d", &u, &v, &w);

		V[u].push_back (pii (w, v));
		V[v].push_back (pii (w, u));
	}

	for (int i = 0;i < c;i ++) {
		int x;
		scanf ("%d", &x);

		M[x-1] ++;
	}

	dijikstra ();

	for (int i = 0;i < n;i ++) {
		if (not use[i] and M[i] > 0) {
			for (int j = 0;j < n;j ++) {
				if (dp[j] == dp[i]) {
					
				}
			}
		}
	}
}