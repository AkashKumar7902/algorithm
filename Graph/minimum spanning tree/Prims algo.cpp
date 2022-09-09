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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> gr[n + 1];

	// vis array will keep track of edges included in MST
	int vis[n + 1] = {};

	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

	// source vertex
	// {weight, node}
	Q.push({0, 1});

	long long int mst = 0;
	while (!Q.empty()) {
		pair<int, int> best = Q.top();
		Q.pop();

		int weight = best.first;
		int to = best.second;

		//not an active edge
		if (vis[to]) continue;

		mst += weight;
		vis[to] = 1;

		for (auto x : gr[to]) {
			if (vis[x.first] == 0) {
				// x.first is not visited means we are at active edge
				// because one part is in MST and other is not.
				Q.push({x.second, x.first});
			}
		}
	}
	cout << mst;
}
