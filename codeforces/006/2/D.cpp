#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16;
const int INF = 0x3f3f3f3f;

struct node {
	int tot, cnt[MAXN];
} mn, cc;

int n, b, a;
int h[MAXN];

inline int fire(const int hp, const int dm) { return hp < 0 ? 0 : hp / dm + 1; }

void gao(int d) {
	if (cc.tot >= mn.tot) return;
	if (d == n - 1) {
		if (h[n-1] < 0) mn = cc;
//		puts("=========="); for (int i=0; i<n; ++i) printf("%d ", h[i]); puts("");
		return;
	}
	int s = fire(h[d-1], b), t = max(s, fire(h[d], a)) + 1;	
	if (d == n - 2) t = max(t, fire(h[d+1], b));
	for (int i=s; i<=t; ++i) {
		cc.tot += i, cc.cnt[d] += i;
		h[d-1] -= b * i, h[d] -= a * i, h[d+1] -= b * i;
		gao(d+1);		
		cc.tot -= i, cc.cnt[d] -= i;
		h[d-1] += b * i, h[d] += a * i, h[d+1] += b * i;
	}
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i=0; i<n; ++i) scanf("%d", h+i);
	mn.tot = INF;
	gao(1);
	printf("%d\n", mn.tot);
	for (int i=0,sum=0; i<n; ++i) for (int j=0; j<mn.cnt[i]; ++j,++sum) {
		printf("%d%s", i+1, sum==mn.tot-1?"\n":" ");
	}
	return 0;
}

// 3479264	 Apr 6, 2013 12:44:12 PM	delta_4d	 D - Lizards and Basements 2	 GNU C++	Accepted	 15 ms	 0 KB
