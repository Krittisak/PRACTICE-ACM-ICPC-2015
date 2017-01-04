#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210;

int n,m,k;
int x[N][N];
char bits[N*N*2];

inline void solveB (int x1, int x2, int y1, int y2) {
	if (x1 <= x2 and y1 <= y2) {
		int n0 = 0,n1 = 0;
		for (int i = x1;i <= x2;i ++) {
			for (int j = y1;j <= y2;j ++) {
				if (x[i][j]) {
					n1 ++;
				} else {
					n0 ++;
				}
			}
		}

		if ((k ++)%50 == 0) {
			printf ("\n");
		}

		if (n0 == 0) {
			printf ("1");
		} else if (n1 == 0) {
			printf ("0");
		} else {
			printf ("D");
			int mx = (x1+x2) >> 1;
			int my = (y1+y2) >> 1;
			solveB (x1, mx, y1, my);
			solveB (x1, mx, my+1, y2);
			solveB (mx+1, x2, y1, my);
			solveB (mx+1, x2, my+1, y2);
		}
	}
}

inline void solveD (int x1, int x2, int y1, int y2) {
	if (x1 <= x2 and y1 <= y2) {
		k ++;
		if (bits[k-1] == '0') {
			for (int i = x1;i <= x2;i ++) {
				for (int j = y1;j <= y2;j ++) {
					x[i][j] = 0;
				}
			}
		} else if (bits[k-1] == '1') {
			for (int i = x1;i <= x2;i ++) {
				for (int j = y1;j <= y2;j ++) {
					x[i][j] = 1;
				}
			}
		} else {
			int mx = (x1+x2) >> 1;
			int my = (y1+y2) >> 1;
			solveD (x1, mx, y1, my);
			solveD (x1, mx, my+1, y2);
			solveD (mx+1, x2, y1, my);
			solveD (mx+1, x2, my+1, y2);
		}
	}
}

int main () {
	char s[110];
	gets (s);
	while (s[0] != '#') {
		char temp[3];
		sscanf (s, "%s %d %d", temp, &n, &m);

		int t = 0;
		while (gets (s) and s[0] != '#' and not (strlen (s) > 2 and s[1] == ' ')) {
			for (int i = 0;s[i];i ++) {
				bits[t ++] = s[i];
			}
		}

		if (temp[0] == 'B') {
			for (int i = 0;i < n;i ++) {
				for (int j = 0;j < m;j ++) {
					x[i][j] = bits[i*m+j]-'0';
				}
			}

			printf ("D%4d%4d", n, m);
			k = 0;
			solveB (0, n-1, 0, m-1);
			printf ("\n");
		} else if (temp[0] == 'D') {
			k = 0;
			solveD (0, n-1, 0, m-1);

			printf ("B%4d%4d", n, m);
			for (int i = 0;i < n;i ++) {
				for (int j = 0;j < m;j ++) {
					if ((i*m+j)%50 == 0) {
						printf ("\n");
					}
					printf ("%d", x[i][j]);
				}
			}
			printf ("\n");
		}
	}
}