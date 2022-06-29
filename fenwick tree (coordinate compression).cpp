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

int a[10000] = {};
int bit[10000] = {};

void update(int i, int inc, int n) {
	while (i <= n) {
		bit[i] += inc;
		i += (i & (-i));
	}
}

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]] = 0;
	}
	int j = 1;
	for (auto &p : mp) {
		p.second = j++;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = mp[a[i]];
	}
	int ans = 0;
	for (int i = n; i >= 1; --i) {
		ans += query(a[i] - 1);
		update(a[i], 1, n);
	}
	cout << ans << endl;
}
