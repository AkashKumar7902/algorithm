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
		l[y].push_back(x);
	}
	void bfs(int src) {
		map<int, int> dist;
		queue<int> q;
		for (auto node_pair : l) {
			int node = node_pair.first;
			dist[node] = INT_MAX;
		}
		dist[src] = 0;
		q.push(src);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					dist[nbr] = dist[node] + 1;
					q.push(nbr);
				}
			}
		}
		for (auto node_pair : l) {
			int node = node_pair.first;
			int d = dist[node];
			cout << "node " << node << " is at a distance of " << d << " from node " << src << endl;
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
	graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.bfs(0);
}
