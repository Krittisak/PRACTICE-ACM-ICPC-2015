#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e3+10;
const double PI = acos (-1);

#define pii pair<double, double>

int n;
pii P,p[N];

int main () {
	while (scanf ("%d", &n) == 1 and n != 0) {
		for (int i = 0;i < n;i ++) {
			scanf ("%lf %lf", &p[i].first, &p[i].second);
		}
		scanf ("%lf %lf", &P.first, &P.second);

		bool ans = false;
		p[n] = p[0];
		for (int i = 0;i < n;i ++) {
			if ((p[i].second > P.second) != (p[i+1].second > P.second) and P.first < (p[i+1].first-p[i].first)*(P.second-p[i].second)/(p[i+1].second-p[i].second)+p[i].first) {
				ans ^= true;
			}
		}

		printf ("%c\n", ans ? 'T' : 'F');
	}
}