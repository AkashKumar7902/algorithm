#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int x, y, GCD;
void extended_euclid(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		GCD = a;
		return;
	}
	extended_euclid(b, a % b);
	int cx = y;
	int cy = x - (a / b) * y;

	x = cx;
	y = cy;

}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	extended_euclid(18, 30);
	cout << x << " " << y << endl;
}
