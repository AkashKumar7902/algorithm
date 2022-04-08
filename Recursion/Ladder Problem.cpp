#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

int f(int n, int k) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		ans += f(n - i, k);
	}
	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	cout << f(n, k);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--)
		solve();
}
