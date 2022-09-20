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

int findSet(int i, int parent[]) {
	if (parent[i] == -1) {
		return i;
	}
	return parent[i] = findSet(parent[i], parent);
}
void unionSet(int x, int y, int parent[], int rank[]) {
	int s1 = findSet(x, parent);
	int s2 = findSet(y, parent);
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n >> m;
	vector<vector<int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		edges[i] = {w, x, y};
	}
	int *parent = new int[n + 1];
	int *rank = new int[n + 1];
	for (int i = 0; i <= n; ++i) {
		parent[i] = -1;
		rank[i] = 1;
	}
	sort(edges.begin(), edges.end());
	long long mst = 0;
	for (int i = 0; i < m; ++i) {
		int s1 = findSet(edges[i][1], parent);
		int s2 = findSet(edges[i][2], parent);
		int wt = edges[i][0];
		if (s1 != s2) {
			unionSet(s1, s2, parent, rank);
			mst += wt;
		}
	}
	cout << mst << endl;
}
