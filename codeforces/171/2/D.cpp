#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 23;
const int INF = 0x3f3f3f3f;

int dp[1<<(MAXN-1)], x[MAXN];

int dfs(int state, int d) {
	if (dp[state]) return dp[state];
	if (state == 1) return dp[state] = 1;
	dp[state] = INF;
	int cc = __builtin_popcount(state), ns = state & ~(1 << d) | 1 << (d - 1);
	for (int i=0; i<d; ++i) for (int j=0; j<=i; ++j) if (x[i] + x[j] == x[d]) {
		dp[state] = min(dp[state], max(cc, dfs(ns|1<<i|1<<j, d-1)));	
	}
	return dp[state];
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	--n;
	dfs(1<<n, n);
	printf("%d\n", dp[1<<n]!=INF?dp[1<<n]:-1);

	return 0;
}

// 3266561 	Mar 8, 2013 7:31:28 PM 	delta_4d 	279D - The Minimum Number of Variables 	GNU C++ 	Accepted 	15 ms 	16400 KB 
