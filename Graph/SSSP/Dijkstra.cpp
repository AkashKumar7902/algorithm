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
	unordered_map<T, list<pair<T, int>>> m;
public:
	void addEdge(T u, T v, int wt, bool bidir = true) {
		m[u].push_back({v, wt});
		if (bidir) {
			m[v].push_back({u, wt});
		}
	}
	void dijsktraSSSP(T src) {
		unordered_map<T, int> dist;
		// set all distances to infinity
		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}
		set<pair<int, T>> s;
		s.insert({0, src});
		dist[src] = 0;
		while (!s.empty()) {
			auto it = *(s.begin());
			T node = it.second;
			int nodeDist = it.first;
			s.erase(s.begin());
			for (auto childPair : m[node]) {
				if (childPair.second + nodeDist < dist[childPair.first]) {
					T dest = childPair.first;
					auto it = s.find({dist[dest], dest});
					if (it != s.end()) {
						s.erase(it);
					}
					dist[dest] = childPair.second + nodeDist;
					s.insert({dist[dest], dest});
				}
			}
		}
		for (auto d : dist) {
			cout << d.first << " is located at distance of " << d.second << endl;
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
	graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.dijsktraSSSP(1);
}
