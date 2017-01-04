#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> VS;

const int N = 30,inf = -1u/4;

int n;
VS a[N];
char s[N];
int ans[N][N];

inline void rec (int st) {
	for (int i = 0;i < n;i ++) {
		ans[i][st] = -1;
	}
	ans[st][st] = 0;

	int s = 1<<st,t = s;
	for (int i = 1;i < n;i ++) {
		for (int j = 0;j < n;j ++) {
			if ((s>>j)&1) {
				continue;
			}

			for (int k = 0;k < a[j].size ();k ++) {
				int l = a[j][k];
				if ((l&s) == l) {
					ans[j][st] = i;
					t |= 1<<j;
				}
			}
		}
		s = t;
	}
}

int main () {
	scanf ("%d", &n);

	for (int i = 0;i < n;i ++) {
		int m;
		scanf ("%d", &m);

		while (m --) {
			scanf ("%s", s);

			int t = 0;
			for (int j = 0;s[j] != 0;j ++) {
				t |= 1<<(s[j]-'a');
			}
			a[i].push_back (t);
		}
	}

	for (int i = 0;i < n;i ++) {
		rec (i);
	}

	for (int i = 0;i < n;i ++) {
		for (int j = 0;j < n;j ++) {
			printf ("%d ", ans[i][j]);
		}
		printf ("\n");
	}
}