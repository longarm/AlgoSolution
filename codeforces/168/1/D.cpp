#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define F first
#define S second
#define OK 0
#define NOTVISIT -1
#define VISITING 1

vector <pair<int, int> > a;
vector <vector<int> > T;
vector <int> step, mark;
int level;

bool dfs(int root) {
	mark[root] = VISITING;	
	for (int i=0; i<T[root].size(); ++i) {
		int u = T[root][i];
		if (mark[u] == VISITING) return false;
		if (mark[u] == NOTVISIT && !dfs(u)) return false;
	}
	mark[root] = OK;
	step[level++] = root;
	return true;
}

int main() {
	int n, m;

	cin >> n >> m;
	a.resize(m); T.resize((m+2)*(n+2));
	int cc = m;
	for (int i=0; i<n; ++i, ++cc) {
		for (int j=0; j<m; ++j) cin >> a[j].F, a[j].S = j;
		sort(a.begin(), a.end());
		for (int j=0; j<m; ++cc) {
			int v = a[j].F;
			if (v == -1) { ++j; continue; }
			for (; j<m&&a[j].F==v; ++j) T[cc].PB(a[j].S), T[a[j].S].PB(cc+1);		
		}
	}
	step.resize(cc); mark.resize(cc, NOTVISIT);
	for (int i=0; i<cc; ++i) if (mark[i] == NOTVISIT && !dfs(i)) { cout << -1 << endl; return 0; } 
	for (int i=cc-1; i>=0; --i) if (step[i] < m) cout << step[i] + 1 << ' '; cout << endl;

	return 0;
}

// 3325391	 Mar 16, 2013 3:21:17 PM	delta_4d	 274D - Lovely Matrix	 GNU C++	Accepted	156 ms	7300 KB
