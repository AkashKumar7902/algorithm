#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define mem1(a) 		memset(a, 1, sizeof(a))
#define mem0(a)			memset(a, 0, sizeof(a))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define ll long long
#define prinst(st)		for(auto &i : st) cout << i << " "; cout << endl;
#define printvec(vec) for(auto elem : vec) cout << elem << " "; cout << endl;
#define printstack(st) while(!st.empty()) cout << st.top() << " ", st.pop(), cout <<endl;

const int N = 100005, M = 22;

struct dsu {
	vector<int> p;
	void init(int NN) {
		p.clear();
		p.resize(NN);
		iota(p.begin(), p.end(), 0);
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, j, k, n, m, ans = 0, sum = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<int>> edges(m);
	for (i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		edges[i] = {w, x, y};
	}
	sort(edges.begin(), edges.end());

	dsu G;
	G.init(n);

	for (i = 0; i < m; ++i) {
		int x = edges[i][1];
		int y = edges[i][2];
		int w = edges[i][0];
		if (G.get(x) != G.get(y)) {
			G.unite(x, y);
			ans += w;
		}
	}

	cout << ans << endl;
}
