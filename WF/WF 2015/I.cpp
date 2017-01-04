#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<double, double>

int n;
double w,u,v,t1,t2;
vector<pii> a;

int main () {
	scanf ("%d %lf %lf %lf %lf %lf", &n, &w, &u, &v, &t1, &t2);

	for (int i = 0;i < n;i ++) {
		char s[2];
		int m;
		scanf ("%s %d", s, &m);

		for (int j = 0;j < m;j ++) {
			double l,p;
			scanf ("%lf %lf", &l, &p);

			if (s[0] == 'E') {
				p = -p;
			}

			a.push_back (pii (p/u-w*(i+1)/v, (p+l)/u-w*i/v));
		}
	}

	sort (a.begin (), a.end ());

	double ans = 0,x = t1;
	for (int i = 0;i < a.size () and a[i].first < t2;i ++) {
		ans = max (ans, a[i].first-x);
		x = max (x, a[i].second);
	}
	ans = max (ans, t2-x);
	printf ("%lf\n", ans);
}