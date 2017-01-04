#include <cstdio>

const int N = 60;

int n,T;

int main () {
  while (scanf ("%d %d", &n, &T) == 2) {
    bool dead = false;
    int ans = n;
    for (int i = 0;i < n;i ++) {
      int x;
      scanf ("%d", &x);

      if (not dead) {
	if (x <= T) {
	  T -= x;
	} else {
	  ans = i;
	  dead = true;
	}
      }
    }
    printf ("%d\n", ans);
  }
}
