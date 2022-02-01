#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> trial_division(ll n) {
	vector<ll> factorization;
	for (ll d : {2, 3, 5}) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (ll d = 7; d * d <= n; d += increments[i++]) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8) {
			i = 0;
		}
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n; cin >> n;
	vector<ll> v = trial_division(n);
	for (auto &i : v)
		cout << i << " ";
	cout << endl;
}
