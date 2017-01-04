#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair <ll, int> pdi;
typedef pair <int, int> pii;
typedef pair <double, pdi> pddi;

const int N = 21;

int n;
double p[4];
double fac[N],f[N][4];
priority_queue<pddi> q;
vector<pii> l;
vector<double> pro;

inline double dfs (int u, ll cnt = 1, int lv = 0) {
	double sum = 0;

	if (l[u].first == -1) {
		sum += pro[u]*cnt*lv;
	} else {
		if (l[u].first == l[u].second) {
			sum += dfs (l[u].first, cnt*2, lv+1);
		} else {
			sum += dfs (l[u].first, cnt, lv+1);
			sum += dfs (l[u].second, cnt, lv+1);
		}
	}

	return sum;
}

int main () {
	scanf ("%d", &n);

	fac[0] = 1;
	for (int i = 1;i <= n;i ++) {
		fac[i] = fac[i-1]*i;
	}

	for (int i = 0;i < 4;i ++) {
		scanf ("%lf", &p[i]);

		f[0][i] = 1;
		for (int j = 1;j <= n;j ++) {
			f[j][i] = f[j-1][i]*p[i];
		}
	}

	for (int a = 0;a <= n;a ++) {
		for (int b = 0;a+b <= n;b ++) {
			for (int c = 0;a+b+c <= n;c ++) {
				int d = n-a-b-c;
				ll cnt = fac[n]/fac[a]/fac[b]/fac[c]/fac[d];
				double prop = f[a][0]*f[b][1]*f[c][2]*f[d][3];

				q.push (pddi (-prop, pdi (cnt, l.size ())));
				l.push_back (pii (-1, -1));
				pro.push_back (prop);
			}
		}
	}

	while (not q.empty ()) {
		pddi u = q.top ();
		q.pop ();

		if (u.second.first == 1) {
			if (q.empty ()) {
				break;
			}
			pddi v = q.top ();
			q.pop ();

			q.push (pddi (u.first+v.first, pii (1, l.size ())));
			l.push_back (pii (u.second.second, v.second.second));
			v.second.first --;
			if (v.second.first > 0) {
				q.push (v);
			}
		} else {
			q.push (pddi (2*u.first, pdi (u.second.first/2, l.size ())));
			l.push_back (pii (u.second.second, u.second.second));
			if (u.second.first%2) {
				u.second.first = 1;
				q.push (u);
			}
		}
	}

	printf ("%lf\n", dfs (l.size ()-1));
}