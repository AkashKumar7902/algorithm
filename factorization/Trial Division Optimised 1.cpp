#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> trial_division(ll n) {
	vector<ll> factorization;
	while (n % 2 == 0) {
		factorization.push_back(2);
		n /= 2;
	}
	for (ll d = 3; d * d <= n; d += 2) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
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
