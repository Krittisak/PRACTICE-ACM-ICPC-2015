#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 51,M = 1e4+2;

int n,m,l;
char s[N][N],word[M];
struct node {
	int x,y,z,w;

	node () { }
	node (int _x, int _y, int _z, int _w = 1) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
} ;
queue<node> q;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool use[N][N][M];

inline bool inBorder (int x, int y) {
	return 0 <= x and x < n and 0 <= y and y < m;
}

inline void add (node u) {
	if (not use[u.x][u.y][u.z]) {
		use[u.x][u.y][u.z] = true;
		q.push (u);
	}
}

int main () {
	scanf ("%d %d", &n ,&m);
	for (int i = 0;i < n;i ++) {
		scanf ("%s", s[i]);
	}
	scanf ("%s", word);
	l = strlen (word);
	word[l ++] = '*';

	add (node (0, 0, 0, 0));
	while (not q.empty ()) {
		node u = q.front ();
		q.pop ();

		if (u.z == l) {
			printf ("%d\n", u.w);
			break;
		}
		if (word[u.z] == s[u.x][u.y]) {
			add (node (u.x, u.y, u.z+1, u.w+1));
		}
		for (int k = 0;k < 4;k ++) {
			node v = u;
			v.w ++;
			while (true) {
				v.x += d[k][0];
				v.y += d[k][1];

				if (not inBorder (v.x, v.y)) {
					break;
				} else if (s[v.x][v.y] != s[u.x][u.y]) {
					add (v);
					break;
				}
			}
		}
	}
}