#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

const int N = 210;

#define pii pair<int, int>

int n;
map<string, int> Map;
vector<int> V[N];
pii dp[N][2];

inline pii comp (pii a, pii b) {
	if (a.first > b.first) {
		return a;
	} else if (a.first < b.first) {
		return b;
	} else {
		return pii (a.first, 1);
	}
}

inline pii add (pii a, pii b) {
	return pii (a.first+b.first, max (a.second, b.second));
}

inline void dfs (int u) {
	dp[u][0] = pii (0, 0);
	dp[u][1] = pii (1, 0);
	for (int i = 0;i < V[u].size ();i ++) {
		int v = V[u][i];
		dfs (v);

		dp[u][0] = add (dp[u][0], comp (dp[v][0], dp[v][1]));

		dp[u][1] = add (dp[u][1], dp[v][0]);
	}
}

int main () {
	while (scanf ("%d", &n) == 1 and n != 0) {
		for (int i = 0;i < n;i ++) {
			V[i].clear ();
		}
		Map.clear ();
		int cnt = 0;

		string boss;
		cin >> boss;
		Map[boss] = cnt;

		for (int i = 1;i < n;i ++) {
			string u,v;
			cin >> u >> v;

			if (Map.find (u) == Map.end ()) {
				Map[u] = ++ cnt;
			}
			if (Map.find (v) == Map.end ()) {
				Map[v] = ++ cnt;
			}

			int a = Map[u],b = Map[v];
			V[b].push_back (a);
		}

		dfs (0);

		pii ans = comp (dp[0][0], dp[0][1]);

		printf ("%d %s\n", ans.first, ans.second == 0 ? "Yes" : "No");
	}
}