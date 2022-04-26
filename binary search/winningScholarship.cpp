/*

Fitzee decided to give 100% scholarship to the needy students.
However, to avoid any losses at the institute, he came up with
a solution. Fitzee has N students and M different coupons. A 
student will get 100% waiver if he gets X discount coupons.

However, in order to get more discount coupon in addition to those
M. Fitzee decided that those who perform badly in the test, need to 
pay additional amount equivalent to Y discount coupons.

Find out the maximum no. of students who can get 100% waiver in
their admission fees.

input format : n, m, x, y

input : 5 10 2 1
output : 5

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

bool func(int n, int mid, int m, int x, int y) {
	if (mid * x <= m + y * (n - mid)) {
		return true;
	}
	return false;
}

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int s = 0;
	int e = n;
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		bool flag = func(n, mid, m, x, y);
		if (flag) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
  
	solve();
  
}





