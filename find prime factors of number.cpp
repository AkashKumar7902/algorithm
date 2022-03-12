// Precomputation Method 

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long

int a[1000000] = {};

void precompute() {
	for (ll i = 2; i < 1000000; ++i) {
		if (!a[i]) {
			a[i] = i;
			for (ll j = i * i; j < 1000000; j += i) {
				a[j] = min(a[i], a[i]);
			}
		}
	}
}

void solve() {
	int n; cin >> n;
	while (n != 1) {
		cout << a[n] << " ";
		n /= a[n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	precompute();
	solve();
}
