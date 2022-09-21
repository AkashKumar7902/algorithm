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

#define INF 10000

vector<vector<int>> floyyd_warshall(vector<vector<int>> graph) {
	vector<vector<int>> dist(graph);
	int v = graph.size();
	for (int k = 0; k < v; ++k) {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
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
	vector<vector<int>> graph = {
		{0, INF, -2, INF},
		{4, 0, 3, INF},
		{INF, INF, 0, 2},
		{INF, -1, INF, 0}
	};
	auto result = floyyd_warshall(graph);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result.size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
