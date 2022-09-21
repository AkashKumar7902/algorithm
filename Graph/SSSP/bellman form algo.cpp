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

vector<int> bellman_ford(int v, int src, vector<vector<int>> edges) {
	vector<int> dist(v + 1, INT_MAX);
	dist[src] = 0;

	// relax all edges v - 1 times
	for (int i = 0; i < v - 1; ++i) {
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[wt]) {
				dist[wt] = dist[u] + wt;
			}
		}
	}

	// negative wt. cycle
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
			cout << "Negative wt. cycle detected" << endl;
			exit(0);
		}
	}
	return dist;
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

	// edge list
	vector<vector<int>> edges;

	for (int i = 0; i < m; ++i) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}

	// bellman algorithm
	vector<int> distances = bellman_ford(n, 1, edges);

	for (int i = 1; i <= n; ++i) {
		cout << "node " << i << " at a distance of " << distances[i] << endl;
	}
}

// input 1 
// 3 3 
// 1 2 3
// 2 3 4 
// 3 1 -10

// input 2 
// 3 3 
// 1 2 3
// 2 3 4 
// 1 3 -10
