#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m,r,c;
char x[N][N];

int main () {
	while (scanf ("%d %d %d %d", &n ,&m, &r, &c) == 4 and n+m+r+c != 0) {
		for (int i = 0;i < n;i ++) {
			scanf ("%s", x[i]);
		}

		int ans = 0;
		for (int i = 0;i < n-r+1;i ++) {
			for (int j = 0;j < m-c+1;j ++) {
				if (x[i][j] == '1') {
					ans ++;
					for (int a = 0;a < r;a ++) {
						for (int b = 0;b < c;b ++) {
							x[i+a][j+b] = ((x[i+a][j+b]-'0')^1)+'0';
						}
					}
				}
			}
		}

		for (int i = 0;i < n;i ++) {
			for (int j = 0;j < m;j ++) {
				if (x[i][j] == '1') {
					ans = -1;
					goto f;
				}
			}
		}
		f:;

		printf ("%d\n", ans);
	}
}