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

class Graph {
	int v;
	list<int> *l;
public:
	Graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x, int y, bool directed = true) {
		l[x].push_back(y);
		if (!directed) {
			l[y].push_back(x);
		}
	}
	bool cycle_helper(int node, bool * visited, bool * stack) {
		visited[node] = true;
		stack[node] = true;
		for (int nbr : l[node]) {
			if (stack[nbr] == true) {
				return true;
			}
			else if (visited[nbr] == false) {
				bool cycle_mila = cycle_helper(nbr, visited, stack);
				if (cycle_mila) {
					return true;
				}
			}
		}
		stack[node] = false;
		return false;
	}
	bool contains_cycle() {
		bool *visited = new bool[v];
		bool *stack = new bool[v];
		for(int i = 0; i < v; ++i){
			visited[i] = stack[i] = false;
		}
		return cycle_helper(0, visited, stack);
	}
};

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2);
	if(g.contains_cycle()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}
