#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 4e4+10,M = 52;

int n;
char s[10];
bool V[M][M] = {false},use[M] = {false},have[M] = {false};

inline bool dfs (int u, int p) {
	if (u == p and use[u]) {
		return true;
	} else if (not use[u]) {
		use[u] = true;

		bool ans = false;
		for (int v = 0;v < M;v ++) {
			if (V[u][v]) {
				ans |= dfs ((v+26)%52, p);
			}
		}

		return ans;
	} else {
		return false;
	}
}

int main () {
	scanf ("%d", &n);

	for (int i = 0;i < n;i ++) {
		scanf ("%s", s);

		for (int j = 0;j < 8;j += 2) {
			int a = M;
			if (s[j+1] == '+') {
				a = s[j]-'A';
			} else if (s[j+1] == '-') {
				a = s[j]-'A'+26;
			}
			if (a == M) {
				continue;
			}
			have[a] = true;
			for (int k = 0;k < 8;k += 2) {
				if (j != k) {
					int b = M;
					if (s[k+1] == '+') {
						b = s[k]-'A';
					} else if (s[k+1] == '-') {
						b = s[k]-'A'+26;
					}
					if (b == M) {
						continue;
					}
					V[a][b] = true;
				}
			}
		}
	}

	bool ans = false;
	for (int i = 0;i < M;i ++) {
		for (int j = 0;j < M;j ++) {
			use[j] = false;
		}
		ans |= dfs (i, i);
	}

	printf ("%s\n", ans ? "unbounded" : "bounded");
}