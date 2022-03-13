// useful for big numbers ( 10 ^ 18) 
// 100 % accuracy upto 3 X 10^(18)
// upon providing a number above 3 X 10 ^(18) 
// the algorithm return prime for a non - prime number. 
// input : 3825123056546413051



#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long

ll modular_exponentiation(ll a, ll d, ll n) {
	a %= n;
	ll res = 1;
	while (d > 0) {
		if (d & 1)
			res = res * a % n;
		a = a * a % n;
		d >>= 1;
	}
	return res;
}

bool miller_rabin(ll n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	
	//now my n is odd therefore n - 1 is even.
	ll d = n - 1, s = 0;
	while (d % 2 == 0) {
		s++;
		d /= 2;
	}
	
	// n - 1 = d * pow(2, s);
	// now d is odd number
	vector<ll> a({2, 3, 5, 7, 11, 13, 17, 19, 23});
	// vector a represents random number.
	for (ll i = 0; i < a.size(); ++i) {
		if (a[i] > n - 2) continue;
		ll ad = modular_exponentiation(a[i], d, n);
		if (ad % n == 1) continue;
		bool prime = false;
		for (ll r = 0; r <= s - 1; ++r) {
			// (2 ^ r) % n
			ll rr = modular_exponentiation (2, r, n);
			// (a ^ (d * 2 * i)) % n
			ll arr = modular_exponentiation(ad, rr, n);
			if (arr % n == n - 1) {
				prime = true;
				break;
			}
		}
		if (prime == false) {
			return false;
		}
	}
	return true;
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
		int n; cin >> n;
		bool flag = miller_rabin(n);
		if (flag )
			cout << "Prime" << endl;
		else
			cout << "Not Prime" << endl;
	}
}
