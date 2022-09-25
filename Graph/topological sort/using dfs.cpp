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

template<typename T>
class graph {
	map<T, list<T>> l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}
	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
		visited[src] = true;
		for (auto nbr : l[src]) {
			if (visited[nbr] == false) {
				dfs_helper(nbr, visited, ordering);
			}
		}
		ordering.push_front(src);
	}
	void dfs() {
		map<T, bool> visited;
		list<T> ordering;
		for (auto p : l) {
			visited[p.first] = false;
		}
		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}
		for (auto node : ordering) {
			cout << node << endl;
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
	cin >> m;
	string x, y;
	graph<string> g;
	for (i = 0; i < m; ++i) {
		cin >> x >> y;
		g.addEdge(x, y);
	}
	g.dfs();
}

// input
/*
7 8
Python dataPreprocessing
Python Pytorch
Python MLbasics
MLbasics DeepLearning
Pytorch DeepLearning
DeepLearning FaceRecognition
Dataset FaceRecognition
*/

//output
/*
Python
Pytorch
dataPreprocessing
MLbasics
DeepLearning
Dataset
FaceRecognition
*/
