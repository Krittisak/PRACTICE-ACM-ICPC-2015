#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define pii pair<double, double>

const int N = 1e5+10;

int n;
pii p[N],s[N];

inline bool comp (pii a, pii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	} else {
		return a.first > b.first;
	}
}

inline double cross (pii a, pii b, pii c) {
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}

inline double Dist (pii a, pii b) {
	return sqrt ((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

inline double perimeter (pii p[], int n) {
	double sum = 0;
	for (int i = 0;i < n;i ++) {
		sum += Dist (p[i], p[i+1]);
	}
	return sum;
}

int main () {
	int test = 0;
	while (scanf ("%d", &n) == 1 and n != 0) {
		for (int i = 0;i < n;i ++) {
			scanf ("%lf %lf", &p[i].first, &p[i].second);
		}

		sort (p, p+n, comp);

		int m = -1;
		for (int i = 0;i < n;i ++) {
			while (m-1 >= 0 and cross (s[m-1], s[m], p[i]) >= 0) m --;
			s[++ m] = p[i];
		}
		for (int i = n-1,t = m;i >= 0;i --) {
			while (m-1 >= t and cross (s[m-1], s[m], p[i]) >= 0) m --;
			s[++ m] = p[i];
		}

		if (test) {
			printf ("\n");
		}
		printf ("Region #%d:\n", ++ test);
		for (int i = 0;i <= m;i ++) {
			if (i) {
				printf ("-");
			}
			printf ("(%.1lf,%.1lf)", s[i].first, s[i].second);
		}
		printf ("\n");
		printf ("Perimeter length = %.2lf\n", perimeter (s, m));
	}
}