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
#define printst(st)		for(auto &i : st) cout << i << " "; cout << endl;
#define printvec(vec) for(auto elem : vec) cout << elem << " "; cout << endl;
#define printstack(st) while(!st.empty()) cout << st.top() << " ", st.pop(), cout <<endl;
#define MOD 1000000007

void solve() {
	int t; cin >> t;
	vector<pair<int, int>> v;
	int m, n;
	for (int i = 0; i < t; ++i) {
		cin >> m >> n;
		v.push_back({n, m});
	}
	sort(v.begin(), v.end());
	int previous = 0;
	int activity = 0;
	for (int i = 0; i < t; ++i) {
		if (v[i].second >= previous) {
			activity++;
			previous = v[i].first;
		}
	}
	cout << activity << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
