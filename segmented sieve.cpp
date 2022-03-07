// prateek narang solution

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long

const int N = 100000;

vector<int> primes;

int p[N] = {0};

void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (p[i] == 0) {
			primes.push_back(i);
			for (int j = i; j <= N; j += i) {
				p[j] = 1;
			}
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
	sieve();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		bool segment[n - m + 1];
		for (int i = 0; i < n - m + 1; ++i) {
			segment[i] = 0;
		}
		for (auto x : primes) {
			if (x * x > n)
				break;
			int start = (m / x) * x;
			if (x >= m and x <= n) {
				start = x * 2;
			}
			for (int i = start; i <= n; i += x) {
				segment[i - m] = 1;
			}
		}
		for (int i = m; i <= n; ++i) {
			if (segment[i - m] == 0 and i != 1) {
				cout << i << endl;
			}
		}
		cout << endl;
	}
}
