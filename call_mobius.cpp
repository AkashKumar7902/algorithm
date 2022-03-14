//
//  mobius function
//



#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long

const int n = 1000000;

int a[n], prime_count[n], mobius[n];
void cal_mobius() {
	for (int i = 1; i < n; i++) {
		a[i] = 1;
	}
	for (int i = 2; i < n; i++) {
		if (prime_count[i]) continue;
		for (int j = i; j < n; j += i) {
			prime_count[j] ++;
			a[j] *= i;
		}
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] == i) {
			// square free number
			if (prime_count[i] % 2 == 1) mobius[i] = -1;
			else mobius[i] = 1;
		}
		else {
			mobius[i] = 0;
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
	cal_mobius();
	for (int i = 0; i < n; ++i) {
		cout << mobius[i] << " ";
	}
}
