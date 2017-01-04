#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef map<VI, int> MVI;

const int N = 110;

int n;
VI V[N],id[N],ans;
MVI Map;
bool use[N] = {false};

int main () {
	scanf ("%d", &n);
	for (int i = 0;i < n;i ++) {
		int m;
		scanf ("%d", &m);

		for (int j = 0;j < m;j ++) {
			int u;
			scanf ("%d", &u);

			V[i].push_back (u-1);
			id[i].push_back (m);
		}
	}

	VI tmp;
	bool change = true;
	while (change) {
		change = false;
		int last = Map.size ();
		Map.clear ();
		int curr = 0;
		for (int i = 0;i < n;i ++) {
			for (int j = 0;j < V[i].size ();j ++) {
				int u = V[i][j];
				int st;
				for (st = 0;V[u][st] != i;st ++) ;

				tmp.clear ();
				for (int k = 0;k < V[u].size ();k ++) {
					tmp.push_back (id[u][(k+st)%V[u].size ()]);
				}

				if (Map.find (tmp) == Map.end ()) {
					Map[tmp] = curr ++;
				}
			}
		}

		for (int i = 0;i < n;i ++) {
			for (int j = 0;j < V[i].size ();j ++) {
				int u = V[i][j];
				int st;
				for (st = 0;V[u][st] != i;st ++) ;

				tmp.clear ();
				for (int k = 0;k < V[u].size ();k ++) {
					tmp.push_back (id[u][(k+st)%V[u].size ()]);
				}

				id[i][j] = Map[tmp];
			}
		}

		change = Map.size () != last;
		last = Map.size ();
		printf ("size : %d\n", last);
	}

	VI tmp2;
	bool none = true;
	for (int i = 0;i < n;i ++) {
		if (use[i]) {
			continue;
		}
		ans.clear ();
		use[i] = true;
		ans.push_back (i+1);
		for (int j = i+1;j < n;j ++) {
			if (id[i].size () != id[j].size ()) {
				continue;
			}

			tmp.clear ();
			for (int k = 0;k < id[i].size ();k ++) {
				tmp.push_back (id[i][k]);
			}
			for (int l = 0;l < id[j].size ();l ++) {
				tmp2.clear ();
				for (int p = 0;p < id[j].size ();p ++) {
					tmp2.push_back (id[j][(l+p)%id[j].size ()]);
				}

				if (tmp == tmp2) {
					ans.push_back (j+1);
					use[j] = true;
					break;
				}
			}
		}
		if (ans.size () > 1) {
			for (int j = 0;j < ans.size ();j ++) {
				printf ("%d ", ans[j]);
			}
			printf ("\n");
			none = false;
		}
	}

	if (none) {
		printf ("none\n");
	}
}