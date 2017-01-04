#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

typedef complex<double> T;
typedef vector<T> VT;

const double PI = acos (-1);

inline void FFT_r (T *A, T *B, size_t p, size_t n, int d) {
	if (n == 1) {
		B[0] = A[0];
		return ;
	}

	FFT_r (A, B, 2*p, n/2, d);
	FFT_r (A+p, B+n/2, 2*p, n/2, d);

	for (int k = 0;k < n/2;k ++) {
		T w = polar (1.0, 2*PI*k/n*d);
		T even = B[k],odd = B[k+n/2];
		B[k] = even + w * odd;
		B[k+n/2] = even - w * odd;
	}
}

inline void FFT (VT &_A, int d) {
	const size_t n = _A.size ();
	T *A = new T[n],*B = new T[n];

	for (int i = 0;i < n;i ++) {
		A[i] = _A[i];
	}

	FFT_r (A, B, 1, n, d);

	for (int i = 0;i < n;i ++) {
		_A[i] = B[i];
	}

	delete[] A;
	delete[] B;

	if (d < 0) {
		for (int i = 0;i < n;i ++) {
			_A[i] /= n;
		}
	}
}

const int N = 5e5+10,M = 1<<20;

VT a (M, 0),b (M, 0),c (M);
double f[N] = {0};
int d[N];

int main () {
	for (int i = 1;i < N;i ++) {
		for (int j = 1;i*j < N;j ++) {
			f[i*j] ++;
		}
	}

	for (int i = 0;i < N;i ++) {
		a[i] = b[i] = f[i];
	}

	FFT (a, 1);
	FFT (b, 1);
	for (int i = 0;i < M;i ++) {
		c[i] = a[i]*b[i];
	}
	FFT (c, -1);

	for (int i = 0;i < N;i ++) {
		double tmp = real (c[i]);
		d[i] = (int)tmp;

		if (tmp-d[i] > 0.5) {
			d[i] ++;
		}
	}

	int t;
	scanf ("%d", &t);

	while (t --) {
		int a,b;
		scanf ("%d %d", &a, &b);

		int ans1 = a,ans2 = d[a];
		for (int i = a+1;i <= b;i ++) {
			if (d[i] > ans2) {
				ans1 = i;
				ans2 = d[i];
			}
		}
		printf ("%d %d\n", ans1, ans2);
	}
}