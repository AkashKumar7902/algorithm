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

class graph {
	map<int, list<int>> l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
	}
	void bfs(int V) {
		int *indegree = new int[V];
		queue<int> q;
		for (int i = 0; i < V; ++i) {
			indegree[i] = 0;
		}
		for (int i = 0; i < V; ++i) {
			for (auto nbr : l[i]) {
				indegree[nbr]++;
			}
		}
		for (int i = 0; i < V; ++i) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
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
	int i, j, n, m;
	cin >> n;
	cin >> m;
	int x, y;
	graph g;
	for (i = 0; i < m; ++i) {
		cin >> x >> y;
		g.addEdge(x, y);
	}
	g.bfs(n);
}

// input
/*
6 6
0 2
1 2
1 4
2 3
3 5
2 5
4 5
*/

// output
/*
0 1 2 4 3 5 
*/
