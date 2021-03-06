#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 99999999999999.9;
const double eps = 1e-8;
const int MAXN = 404 << 1;

int x[MAXN], y[MAXN], p[MAXN];
int f[MAXN][MAXN];
double c[MAXN][MAXN];
double d[MAXN];
queue <int> q;
bool in[MAXN];

inline int L(const int x) { return x << 1; }
inline int R(const int x) { return L(x) ^ 1 ; }
inline bool equ(const double x, const double xx) { return fabs(x - xx) < eps; }

int main() {
	int i, j, k;
	int m, n;
	int S, T;
	double tot(0);

	scanf("%d", &n);
	S = 0, T = R(n);
	for (i=S; i<=T; ++i) fill(c[i], c[i]+T+1, INF);
	for (i=1; i<=n; ++i) {
		scanf("%d%d", x+i, y+i);
		f[S][i] = 1, f[i+n][T] = 2;
		c[S][i] = 0, c[i+n][T] = 0;
	}
	for (i=1; i<=n; ++i) for (j=1; j<=n; ++j) if (y[i] < y[j]) {
		f[i][j+n] = 1; 
		c[i][j+n] = hypot(x[i]-x[j], y[i]-y[j]), c[j+n][i] = -c[i][j+n];
	}
//	for (i=S; i<=T; ++i) {
//		printf("%d: ", i);
//		for (j=S; j<=T; ++j) printf("%d ", f[i][j]);
//		puts("");
//	}
	int tc(n-1);
	while (tc--) {
		while (!q.empty()) q.pop();
		memset(in, false, sizeof(in));
		fill(d, d+T+1, INF);
		q.push(S);
		d[S] = 0, in[S] = true;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			in[t] = false;
			for (i=S; i<=T; ++i) if (f[t][i] && d[t] + c[t][i] < d[i]) {
				d[i] = d[t] + c[t][i];
				p[i] = t;
				if (!in[i]) {
					q.push(i);
					in[i] = true;
				}
			} 
		}
		if (equ(d[T], INF)) {
			puts("-1");
			return 0;
		}
//		for (i=S; i<=T; ++i) printf("%.7lf ", d[i]); puts("");
		k = T;
		while (k != S) {
			tot += c[p[k]][k];
			++f[k][p[k]], --f[p[k]][k];
			k = p[k];	
		}
	}
	printf("%.16lf\n", tot);

	return 0;
}

// 3238299	 Mar 4, 2013 5:49:05 PM	delta_4d	 277E - Binary Tree on Plane	 GNU C++	Accepted	 1203 ms	 7700 KB
