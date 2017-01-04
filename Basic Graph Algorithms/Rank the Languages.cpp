#include <cstdio>
#include <algorithm>

using namespace std;

#define pii pair <int, int>

const int N = 1e3+10;

int n,m;
pii c[30];
char s[N][N];

inline void dfs (int i, int j, char a) {
	if (0 <= i and i < n and 0 <= j and j < m and a == s[i][j]) {
		s[i][j] = 0;
		dfs (i, j+1, a);
		dfs (i, j-1, a);
		dfs (i+1, j, a);
		dfs (i-1, j, a);	
	}
}

inline bool comp (pii a, pii b) {
	return a.first != b.first ? a.first > b.first : a.second < b.second;
}

int main () {
	int t;
	scanf ("%d", &t);

	for (int Case = 1;Case <= t;Case ++) {
		scanf ("%d %d", &n, &m);

		for (int i = 0;i < n;i ++) {
			scanf ("%s", s[i]);
		}

		for (int i = 0;i < 26;i ++) {
			c[i] = pii (0, i);
		}

		for (int i = 0;i < n;i ++) {
			for (int j = 0;j < m;j ++) {
				if (s[i][j] > 0) {
					c[s[i][j]-'a'].first ++;
					dfs (i, j, s[i][j]);
				}
			}
		}

		printf ("World #%d\n", Case);

		sort (c, c+26, comp);

		for (int i = 0;i < 26;i ++) {
			if (c[i].first > 0) {
				printf ("%c: %d\n", c[i].second+'a', c[i].first);
			}
		}
	}
}