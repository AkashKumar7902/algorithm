
class Graph {
	int V;
	list<pair<int, int>> l;
public:
	Graph(int v) {
		this->V = v;
	}
	void addEdge(int x, int y) {
		l.push_back({x, y});
	}
	int findset(int i, int *parent) {
		if (parent[i] == -1) {
			return i;
		}
		return parent[i] = findset(parent[i], parent);
	}
	void union_set(int x, int y, int *parent, int rank[]) {
		int s1 = findset(x, parent);
		int s2 = findset(y, parent);
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
	bool contains_cycle() {
		int *parent = new int[V];
		int *rank = new int[V];
		for (int i = 0; i < V; ++i) {
			parent[i] = -1;
			rank[i] = 1;
		}
		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;
			int s1 = findset(i, parent);
			int s2 = findset(j, parent);
			if (s1 != s2) {
				union_set(s1, s2, parent, rank);
			}
			else {
				return true;
			}
		}
		return false;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	cout << g.contains_cycle() << endl;
}
