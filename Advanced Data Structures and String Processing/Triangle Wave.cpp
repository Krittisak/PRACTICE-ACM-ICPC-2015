#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	int test;
	scanf ("%d", &test);
	for (int Case = 0;Case < test;Case ++) {
		int n,m;
		scanf ("%d %d", &n, &m);

		if (Case > 0) {
			printf ("\n");
		}
		for (int k = 0;k < m;k ++) {
			if (k > 0) {
				printf ("\n");
			}
			for (int i = 1;i <= n;i ++) {
				for (int j = 0;j < i;j ++) {
					printf ("%d", i);
				}
				printf ("\n");
			}
			for (int i = n-1;i >= 1;i --) {
				for (int j = 0;j < i;j ++) {
					printf ("%d", i);
				}
				printf ("\n");
			}
		}
	}
}