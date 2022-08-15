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

vector<int> gr[N], grr[N];
vector<int> order;
int vis[N], comp[N];
vector<int> in_comp[N];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x);
		}
	}
	order.push_back(cur);
}

void reverse_dfs(int cur, int col) {
	vis[cur] = 1;
	in_comp[col].push_back(cur);
	comp[cur] = col;
	for (auto x : grr[cur]) {
		if (!vis[x]) {
			reverse_dfs(x, col);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		grr[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	memset(vis, 0, sizeof(vis));
	int component = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (!vis[order[i]]) {
			reverse_dfs(order[i], component);
			component++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << i << "->" << comp[i] << '\n';
	}
}
