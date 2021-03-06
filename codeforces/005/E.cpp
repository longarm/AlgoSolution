#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;
const int INF = 0x3f3f3f3f;

int h[MAXN], r[MAXN], c[MAXN];
bool v[MAXN];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	long long tot = 0;

	cin >> n;
	for (int i=0; i<n; ++i) cin >> h[i];
	rotate(h, max_element(h, h+n), h+n);
	h[n] = INF, r[n] = n;
	for (int i=n-1; i>=0; --i) {
		for (r[i]=i+1; h[i]>h[r[i]]; tot+=c[r[i]]+1, r[i]=r[r[i]]);
		if (r[i] < n && h[i] != h[r[i]]) ++tot;
		if (r[i] < n && h[i] == h[r[i]]) c[i] = c[r[i]] + 1, r[i] = r[r[i]], tot += c[i] + (r[i] < n);
	}
//	for (int i=0; i<n; ++i) printf("%d ", c[i]); puts("");
	for (int i=1,j=0; i<n; ++i) if (h[i] >= j) v[i] = true, j = h[i];
	for (int i=n-1,j=0; !v[i]&&i>0; --i) if (h[i] >= j) ++tot, j = h[i];
	cout << tot << endl;

	return 0;
}

// 3477116	 Apr 5, 2013 6:45:36 PM	delta_4d	 E - Bindian Signalizing	 GNU C++	Accepted	265 ms	12724 KB
