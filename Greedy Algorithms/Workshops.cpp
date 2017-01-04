#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

#define pii pair<int, int>

int w,r;
pii p[N],s[N];

inline bool comp (pii a, pii b) {
	return a.second < b.second;
}

int main () {
	int trial = 1;
	while (scanf ("%d", &w) == 1 and w) {
		for (int i = 0;i < w;i ++) {
			scanf ("%d %d", &p[i].first, &p[i].second);
		}

		scanf ("%d", &r);
		for (int i = 0;i < r;i ++) {
			int a,b;
			scanf ("%d %d:%d", &s[i].first, &a, &b);
			s[i].second = (a-14)*60+b;
		}

		sort (p, p+w, comp);
		sort (s, s+r, comp);

		multiset<int> S;
		int j;
		for (int i = j = 0;i < r;i ++) {
			for (;j < w and p[j].second <= s[i].second;j ++) {
				S.insert (p[j].first);
			}

			multiset<int>::iterator it = S.upper_bound (s[i].first);
			if (it != S.begin ()) {
				it --;
				S.erase (it);
			}
		}
		for (;j < w;j ++) {
			S.insert (p[j].first);
		}

		int sum = 0;
		for (multiset<int>::iterator i = S.begin ();i != S.end ();i ++) {
			sum += *i;
		}

		if (trial > 1) {
			printf ("\n");
		}
		printf ("Trial %d: %d %d\n", trial ++, S.size (), sum);
	}
}